// BUTTONS FUNCTIONS

void b_l_fun ()
{
  if (f_engine == true || f_engine_start == true || f_engine_scale == true) {}
  else if (timer_button.available())
  {
    switch (menu)
    {
      case general:
        if (marker <= 3 && marker > 0) marker--;
        break;

      case recipie:
        if (marker_sub <= 4 && marker_sub > 0) marker_sub--;
        break;

      case user_choice:
        if (flag_subMenu == true && marker_sub < 6) {
          formulas[5][marker_sub] = formulas[5][marker_sub] - 5;
        }
        else
        {
          if (marker_sub <= 6 && marker_sub >= 0 && marker_sub > 0)marker_sub--;
        }
        break;

      case clean:
        break;

      case settings:
        if (marker_sub < 4 && marker_sub >= 0) marker_sub--;
        break;
      case settingsEdit:
        if (flag_subMenu == true && formulas[which_formula][which_pomp] > 0 )
        {
          formulas[which_formula][which_pomp] = formulas[which_formula][which_pomp] - 5;
        }
        else
        {
          if (marker_sub < 6 && marker_sub >= 0)
          {
            marker_sub--;
            which_pomp--;
          }
        }
        break;
    }
    timer_button.restart();
  }
}

void b_r_fun ()
{
  if (f_engine == true || f_engine_start == true || f_engine_scale == true) {}
  else if (timer_button.available())
  {
    switch (menu)
    {
      case general:
        if (marker < 3 && marker >= 0) marker++;
        break;

      case recipie:
        if (marker_sub < 4 && marker_sub >= 0) marker_sub++;
        break;

      case user_choice:
        if (flag_subMenu == true && marker_sub < 6) {
          formulas[5][marker_sub] = formulas[5][marker_sub] + 5;
        }
        else {
          if (marker_sub < 6 && marker_sub >= 0) marker_sub++;
        }
        break;

      case clean:
        break;

      case settings:
        if (marker_sub < 4 && marker_sub >= 0) marker_sub++;
        break;
      case settingsEdit:
        if (flag_subMenu == true)
        {
          formulas[which_formula][which_pomp] = formulas[which_formula][which_pomp] + 5;
        }
        else
        {
          if (marker_sub < 6 && marker_sub >= 0)
          {
            marker_sub++;
            which_pomp++;
          }
        }
        break;

    }
    timer_button.restart();
  }
}

void b_ok_fun ()
{
  if (f_engine == true || f_engine_start == true || f_engine_scale == true) {}
  else if (timer_button.available())
  {
    menu = marker + 1;

    switch (menu)
    {
      case general:
        break;

      case recipie: //Recipie menu
        if (do_once == true) trigger_engine(marker_sub);
        else do_once = true;
        break;

      case user_choice:  //User choice menu
        if (marker_sub == 6)
        {
          trigger_engine(5);
          marker_sub = 0;
        }
        else if (flag_subMenu == true)
        {
          flag_subMenu = false;
        }
        else if (do_once == true) flag_subMenu = true;
        else do_once = true;
        break;

      case clean: //Cleaning menu
        flag_clean = true;
        if (do_once == true)
        {
          flag_subMenu = true;
          trigger_engine(6);
        }
        else do_once = true;
        break;

      case settings:
        //Settings menu
        if (do_once == true)
        {
          menu = settingsEdit;
        }
        else do_once = true;
        break;

      case settingsEdit:
        if (do_once == true)
        {
          if (flag_subMenu == true)
          {
            flag_subMenu = false;
          }
          else flag_subMenu = true;
        }
        else do_once = true;
        break;

    }
    timer_button.restart();
  }
}

void b_b_fun ()
{
  if (timer_button.available())
  {
    switch (menu)
    {
      case settingsEdit:
        menu = settings;
        which_pomp = 0;
        do_once = false;
        flag_subMenu = false;
        break;

      default:
        flag_subMenu = false;
        flag_clean = false;
        do_once = false;
        menu = 0;
        marker_sub = 0;
        //  marker = 0;
        break;
    }
    if (f_engine_start == true || f_engine_scale == true)
    {
      engine_choice (0, 0, true);
      engine_monitor ();
      which_pomp = 7;
    }
    timer_button.restart();
  }
}

void b_flow_fun ()
{
  if (f_engine == true || f_engine_start == true || f_engine_scale == true) {}
  else if (timer_button.available())
  {
    if (which_mode == false)
    {

      which_mode = true;
    }
    else
    {
      which_mode = false;
    }
    timer_button.restart();
  }
}

void led_button ()
{
      if (which_mode == false)
    {
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
  
    if (which_mode == true)
    {
      digitalWrite(green_led, HIGH);
      digitalWrite(red_led, LOW);
    }
}
