#pragma once

/* SPDX-License-Identifier: GPL-3.0-or-later */

#include <cstdio>

namespace examples
{
/**
 * Example to test UI.
 */
struct Ui
{
  static consteval auto name() { return "UI example"; }
  static consteval auto c_name() { return "avnd_ui"; }
  static consteval auto uuid()
  {
    return "e1f0f202-6732-4d2d-8ee9-5957a51ae667";
  }

  struct ins
  {
    struct
    {
      static consteval auto name() { return "Input"; }
      double** samples;
      int channels;
    } audio;

    struct
    {
      static consteval auto name() { return "Int control"; }

      // The reflection system will look for common widget names in here.
      // First one it finds will be used.
      enum widget
      {
        slider
      };

      static consteval auto range()
      {
        struct
        {
          const int min = 0;
          const int max = 10;
          const int init = 3;
        } c;
        return c;
      }

      static void display(char* buf, int v) noexcept
      {
        snprintf(buf, 16, "%d dabloons", v);
      }

      int value;
    } int_ctl;

    struct
    {
      static consteval auto name() { return "Float control"; }

      enum widget
      {
        knob
      };

      static consteval auto range()
      {
        struct
        {
          const float min = 0;
          const float max = 10;
          const float init = 3;
        } c;
        return c;
      }

      float value;
    } float_ctl;
  } inputs;

  struct
  {
    struct
    {
      static consteval auto name() { return "Output"; }
      double** samples;
      int channels;
    } audio;
  } outputs;

  void operator()(int N) { }
  
  struct layout {
      enum { vbox };
      static constexpr auto name() { return "Main"; }
      
      struct {
        enum { hbox };
        decltype(&ins::float_ctl) float_widget = &ins::float_ctl;
        decltype(&ins::int_ctl) int_widget = &ins::int_ctl;
      } widgets;
      
      struct {
          enum { spacing };
          static constexpr auto width() { return 20; }
          static constexpr auto height() { return 20; }
      } a_spacing;
      
      struct {
        enum { group };
        static constexpr auto name() { return "Group"; }
        struct {
          enum { hbox };
          const char* l1 = "label 1";
          const char* l2 = "label 2";
        } a_hbox;
      } b_group; 
      
      struct {
          enum { spacing };
          static constexpr auto width() { return 20; }
          static constexpr auto height() { return 20; }
      } b_spacing;
      
      struct {
        enum { tabs };
        static constexpr auto name() { return "Tabs"; }
        
        struct {
          enum { hbox };
          static constexpr auto name() { return "HBox"; }
          const char* l1 = "label 3";
          const char* l2 = "label 4";
        } a_hbox;
        
        struct {
          enum { vbox };
          static constexpr auto name() { return "VBox"; }
          const char* l1 = "label 5";
          const char* l2 = "label 6";
        } a_vbox;
      } a_tabs;
      
      struct {
        enum { split };
        static constexpr auto name() { return "split"; }
        static constexpr auto width() { return 400; }
        static constexpr auto height() { return 200; }
        const char* l1 = "some long foo";
        const char* l2 = "other bar";
      } a_split;
  };
};
}
