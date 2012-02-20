#include <gtest/gtest.h>
#include <glib-object.h>

#include <UnityCore/GLibWrapper.h>
#include <UnityCore/Results.h>
#include <UnityCore/ResultIterator.h>

#include "test_utils.h"

using namespace std;
using namespace unity::dash;

namespace
{

static const string swarm_name = "com.canonical.test.resultsmodel";
static const unsigned int n_rows = 200;

static void WaitForSynchronize(Results& model)
{
  ::Utils::WaitForModelSynchronize<Result>(model, n_rows);
}

TEST(TestResults, TestConstruction)
{
  Results model;
  model.swarm_name = swarm_name;
}

TEST(TestResults, TestSynchronization)
{
  Results model;
  model.swarm_name = swarm_name;

  WaitForSynchronize(model);
  EXPECT_EQ(model.count, n_rows);
}

TEST(TestResults, TestRowsValid)
{
  Results model;
  model.swarm_name = swarm_name;

  WaitForSynchronize(model);
 
  ResultIterator iter(model.model);
  unsigned int i = 0;
  for (Result result : model)
  //for (auto iter = model.begin(); iter != model.end(); iter++)
  {
    if (i > n_rows)
      break;

    //Result adaptor = *iter;
    unity::glib::String tmp(g_strdup_printf("Result%d", i));
    string value = tmp.Str();
    EXPECT_EQ(result.uri(), value);
    EXPECT_EQ(result.icon_hint(), value);
    EXPECT_EQ(result.category_index(), i);
    EXPECT_EQ(result.mimetype(), value);
    EXPECT_EQ(result.name(), value);
    EXPECT_EQ(result.comment(), value);
    EXPECT_EQ(result.dnd_uri(), value);
    i++;
  }
}

// We're testing the model's ability to store and retrieve random pointers
TEST(TestResults, TestSetGetRenderer)
{
  Results model;
  model.swarm_name = swarm_name;

  WaitForSynchronize(model);

  for (unsigned int i = 0; i < n_rows; i++)
  {
    Result adaptor = model.RowAtIndex(i);

    char* value = g_strdup_printf("Renderer%d", i);
    adaptor.set_renderer<char*>(value);
  }

  for (unsigned int i = 0; i < n_rows; i++)
  {
    Result adaptor = model.RowAtIndex(i);

    unity::glib::String value(adaptor.renderer<char*>());
    unity::glib::String renderer(g_strdup_printf("Renderer%d", i));

    EXPECT_EQ(value.Str(), renderer.Str());
  }
}

}
