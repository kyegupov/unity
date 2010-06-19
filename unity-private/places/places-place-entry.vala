/*
 * Copyright (C) 2010 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

namespace Unity.Places
{
  /**
   * Represents a PlaceEntry through a .place file ("offline") and then through
   * DBus ("online").
   **/
  public class PlaceEntry : Object
  {
    public struct RenderInfo
    {
      string default_renderer;
      string groups_model;
      string results_model;

      HashTable<string, string> renderer_hints;
    }

    /* Properties */
    public string? dbus_name   { get; construct; }
    public string? dbus_path   { get; construct; }
    public string  icon        { get; construct set; }
    public string  name        { get; construct set; }
    public string  description { get; construct set; }

    public uint     position  { get; set; }
    public string[] mimetypes { get; set; }
    public bool     sensitive { get; set; }

    public string   sections_model_name { get; set; }
    public HashTable<string, string> hints { get; set; }

    public bool    show_global { get; construct set; }
    public bool    show_entry  { get; construct set; }

    private bool _active = false;
    public bool active {
      get { return _active; }
      set {
        if (_active != value)
          {
            _active = value;
            service.set_active (_active);
          }
      }
    }

    private Dee.Model? _sections_model = null;
    public Dee.Model? sections_model {
      get {
        if (_sections_model is Dee.Model == false)
          {
            if (sections_model_name != null)
              {
                _sections_model = new Dee.SharedModel.with_name (sections_model_name);
                (_sections_model as Dee.SharedModel).connect ();
              }
          }
        return _sections_model;
      }
      set {
        _sections_model = value;
      }
    }

    public RenderInfo entry_renderer_info;

    /* Whether the Entry is available on the bus, this is only when we want to
     * do optimisations for startup (showing the entries before actually
     * starting the daemon. We can also abuse this for testing :)
     */
    public bool   online    { get; construct set; }

    private DBus.Connection?     connection;
    private dynamic DBus.Object? service;

    public PlaceEntry (string dbus_name, string dbus_path)
    {
      Object (dbus_name:dbus_name, dbus_path:dbus_path);
    }

    public PlaceEntry.with_info (string dbus_name,
                                 string dbus_path,
                                 string name,
                                 string icon,
                                 string description,
                                 bool   show_global,
                                 bool   show_entry)
    {
      Object (dbus_name:dbus_name,
              dbus_path:dbus_path,
              name:name,
              icon:icon,
              description:description,
              show_global:show_global,
              show_entry:show_entry);
    }

    construct
    {
      online = false;
    }

    /*
     * Public Methods
     */
    public void update_info (GLib.ValueArray value_array)
                             requires (value_array.n_values == 10)
    {
      /* Un-marshal the array and update our information */
      name = value_array.get_nth (1).get_string ();
      icon = value_array.get_nth (2).get_string ();
      position = value_array.get_nth (3).get_uint ();
      sensitive = value_array.get_nth (5).get_boolean ();
      sections_model_name = value_array.get_nth (6).get_string ();

      /* FIXME: Need to unmarshal the rest of the data too */

      /* Unmarshal the RenderInfo */
      unowned ValueArray ea = (ValueArray)(value_array.get_nth (8).get_pointer ());
      entry_renderer_info.default_renderer = ea.get_nth (0).get_string ();
      entry_renderer_info.groups_model = ea.get_nth (1).get_string ();
      entry_renderer_info.results_model = ea.get_nth (2).get_string ();
    }

    public new void connect ()
    {
      if (online == true)
        return;

      /* Grab the entry off DBus */
      try {
        connection = DBus.Bus.get (DBus.BusType.SESSION);
        service = connection.get_object (dbus_name,
                                         dbus_path,
                                         "com.canonical.Unity.PlaceEntry");
      } catch (Error e) {
        warning (@"Unable to connect to $dbus_path on $dbus_name: %s",
                 e.message);
        return;
      }

      online = true;
    }

    public void set_search (string search, HashTable<string, string> hints)
    {
      uint id;

      id = service.set_search (search, hints);
    }

    public void set_active_section (uint section_id)
    {
      service.set_active_section (section_id);
    }

    public void set_global_search (string                    search,
                                   HashTable<string, string> hints)
    {
      service.set_global_search (search, hints);
    }

    /*
     * Private Methods
     */
  }
}

