// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2012 Canonical Ltd
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
 * Authored by: Michal Hruby <michal.hruby@canonical.com>
 */

#include <list>
#include <algorithm>
#include <gmock/gmock.h>
#include <UnityCore/GLibWrapper.h>
#include <UnityCore/Results.h>
#include <UnityCore/ResultIterator.h>

#include <dee.h>

using namespace std;
using namespace testing;
using namespace unity;
using namespace unity::glib;
using namespace unity::dash;

namespace
{

class TestResultIterator : public ::testing::Test
{
public:
  TestResultIterator()
    : results(new Results(ModelType::LOCAL))
  {
    dee_model_set_schema (results->model(), 
                          "s", "s", "u", "s", "s", "s", "s", NULL);
  }

  void AddResult(std::string const& uri, std::string const& name)
  {
    dee_model_append(results->model(),
                     uri.c_str(),  // uri
                     "icon",       // icon-hint
                     0,            // category
                     "text/plain", // mimetype
                     name.c_str(), // display name
                     "",           // comment
                     uri.c_str()); // dnd-uri
  }

  Results::Ptr results;
};

TEST_F(TestResultIterator, TestNullModel)
{
  Object<DeeModel> model;
  ResultIterator it(model);

  EXPECT_TRUE(it.IsLast());
  // first could be undefined, but let's make sure the behaviour doesn't change
  EXPECT_TRUE(it.IsFirst());
}

TEST_F(TestResultIterator, TestEmpty)
{
  ResultIterator it(results->model());

  EXPECT_TRUE(it.IsLast());
  // first could be undefined, but let's make sure the behaviour doesn't change
  EXPECT_TRUE(it.IsFirst());
}

TEST_F(TestResultIterator, TestNonEmpty)
{
  AddResult("mailto:nospam@example.org", "Email");

  ResultIterator it(results->model());

  EXPECT_TRUE(it.IsFirst());
  EXPECT_FALSE(it.IsLast());
}

TEST_F(TestResultIterator, TestCopy)
{
  AddResult("mailto:nospam@example.org", "Email");

  ResultIterator one(results->model());
  ResultIterator two(one);

  EXPECT_EQ(one, two);

  ResultIterator const& original = two++;
  EXPECT_EQ(original, one);
  EXPECT_NE(one, two);
}

TEST_F(TestResultIterator, TestIncrement)
{
  AddResult("file:///foo.txt", "Result #1");
  AddResult("file:///qoo.txt", "Result #2");

  ResultIterator it(results->model());

  EXPECT_EQ((*it).uri(), "file:///foo.txt");
  EXPECT_EQ((*it).name(), "Result #1");

  it++;
  EXPECT_EQ((*it).uri(), "file:///qoo.txt");
  EXPECT_EQ((*it).name(), "Result #2");

  it++;
  EXPECT_TRUE(it.IsLast());
  EXPECT_FALSE(it.IsFirst());
}


} // Namespace
