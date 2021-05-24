void loop()
{
  lcd_print();
  if (flag_clean == true) which_mode = false;
  if (which_mode == false)
  {
    if (f_engine_start == true)
    {
      engine_stop();
      engine_monitor();
    }
    else if (f_engine == true)
    {
      engine_start();
    }
  }
  else
  {
    if (f_engine == true) engine_control_scale();
  }

  blik_LED();

  if (timer_draw_menu.available())
  {
    draw_menu();
    timer_draw_menu.restart();
  }
led_button ();
}
