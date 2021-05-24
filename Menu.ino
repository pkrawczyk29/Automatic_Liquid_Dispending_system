//Functions to organize menu

void draw_menu () //Case for choosing which function you need to use
{
  if (f_engine_start == false && f_engine_scale == false)
  {
    switch (menu)
    {
      case general:
        draw_general_case();
        break;
      case recipie:
        recipie_fun();
        break;
      case user_choice:
        user_choice_fun();
        break;
      case clean:
        clean_test();
        break;
      case settings:
        settings_test();
        break;
      case settingsEdit:
        settings_edit();
        break;
      default:
        lcd_pass("Error");
        break;
    }
  }
  else lcd_pass("Processing");

}

//Main Menu
void draw_general_case()
{
  switch (marker)
  {
    case 0:
      lcd_pass("Recipie");
      break;
    case 1:
      lcd_pass("User Choice");
      break;
    case 2:
      lcd_pass("Clean");
      break;
    case 3:
      lcd_pass("Settings");
      break;
    default:
      break;
  }
}

//Formula Menu
void recipie_fun()
{
  switch (marker_sub)
  {
    case 0:
      lcd_pass("Formula 1");
      break;
    case 1:
      lcd_pass("Formula 2");
      break;
    case 2:
      lcd_pass("Formula 3");
      break;
    case 3:
      lcd_pass("Formula 4");
      break;
    case 4:
      lcd_pass("Formula 5");
      break;
  }
}

//Menu for user-choic-recipie
void user_choice_fun()
{
  switch (marker_sub)
  {
    case 0:
      lcd_pass("Pomp 1");
      lcd.setCursor(8, 1);
      lcd.print(formulas[5][0]);
      break;
    case 1:
      lcd_pass("Pomp 2");
      lcd.setCursor(8, 1);
      lcd.print(formulas[5][1]);
      break;
    case 2:
      lcd_pass("Pomp 3");
      lcd.setCursor(8, 1);
      lcd.print(formulas[5][2]);
      break;
    case 3:
      lcd_pass("Pomp 4");
      lcd.setCursor(8, 1);
      lcd.print(formulas[5][3]);
      break;
    case 4:
      lcd_pass("Pomp 5");
      lcd.setCursor(8, 1);
      lcd.print(formulas[5][4]);
      break;
    case 5:
      lcd_pass("Pomp 6");
      lcd.setCursor(8, 1);
      lcd.print(formulas[5][5]);
      break;
    case 6:
      lcd_pass("Make a recipie");
      break;
  }
}

// Cleaning menu
void clean_test()
{
  if (flag_subMenu == true)
  {
    lcd_pass("Clean");
    menu = 0 ;
    marker = 2 ;
    do_once = false;
  }
  else lcd_pass("Prepare cleaner");
}

//Settings menu
void settings_test()
{
      switch (marker_sub)
    {
      case 0:
        lcd_pass("Formula 1");
        which_formula = 0;
        break;
      case 1:
        lcd_pass("Formula 2");
        which_formula = 1;
        break;
      case 2:
        lcd_pass("Formula 3");
        which_formula = 2;
        break;
      case 3:
        lcd_pass("Formula 4");
        which_formula = 3;
        break;
      case 4:
        lcd_pass("Formula 5");
        which_formula = 4;
        break;
    }
}
void settings_edit()
{
  if (flag_subMenu == false)
  {
    switch (marker_sub)
    {
      case 0:
        lcd_pass("Pomp 1");
        lcd.setCursor(8, 1);
        lcd.print(formulas[which_formula][which_pomp]);
        break;
      case 1:
        lcd_pass("Pomp 2");
        lcd.setCursor(8, 1);
        lcd.print(formulas[which_formula][which_pomp]);
        break;
      case 2:
        lcd_pass("Pomp 3");
        lcd.setCursor(8, 1);
        lcd.print(formulas[which_formula][which_pomp]);
        break;
      case 3:
        lcd_pass("Pomp 4");
        lcd.setCursor(8, 1);
        lcd.print(formulas[which_formula][which_pomp]);
        break;
      case 4:
        lcd_pass("Pomp 5");
        lcd.setCursor(8, 1);
        lcd.print(formulas[which_formula][which_pomp]);
        break;
      case 5:
        lcd_pass("Pomp 6");
        lcd.setCursor(8, 1);
        lcd.print(formulas[which_formula][which_pomp]);
        break;
    }
  }
}
