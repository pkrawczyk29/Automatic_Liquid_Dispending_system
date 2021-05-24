
//LCD Function

//Passed string is copied to text
void lcd_pass(char* passedString)
{
  if (strcmp(passedString, text) != 0)
  {
    strcpy(text, passedString);
    lcd_flag = true;
  }
}

//Printing current text
void lcd_print()
{
  if (lcd_flag == true) {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print(text);
  }
}
