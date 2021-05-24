//Shift Register Function 

//Timers Declaration
Timer pomp1;
Timer pomp2;
Timer pomp3;
Timer pomp4;
Timer pomp5;
Timer pomp6;
uint8_t pinValues[] = { B00000000 };

// Functions 
void trigger_engine(int i)  // short function to trigger engine
{
  which_formula = i;
  f_engine = true;
}

void engine_monitor ()  // function to monitor shift register and reset flags to default option
{
  bool f_monitorSr1 = false, f_monitorSr2 = false;
  uint8_t stateOfPin1[8] , stateOfPin2[8];
  for (int i = 0; i < 9; i++)
  {
    stateOfPin1[i] = sr1.get(i);
    if (stateOfPin1[i] == HIGH) f_monitorSr1 = true;
  }
  for (int i = 0; i < 9; i++)
  {
    stateOfPin2[i] = sr2.get(i);
    if (stateOfPin2[i] == HIGH) f_monitorSr2 = true;
  }

  if (f_monitorSr1 == false && f_monitorSr2 == false)
  {
    f_engine_start = false;
    f_engine_scale = false;
//    wchich_pomp = wchich_pomp + 1;  // do wagi
  }
}


//@params:
//   engine - which engine is edited
//   state - in witch direction engine need to be turn on:
//           0 - turned off
//           1 - left
//           2 - right
//    updateAll - if 0 is no update register if 1 register will be update

void engine_choice(byte engine, byte state, bool noUpdate)   // choice wich engine turn on
{
  if (engine == 0) //engine = 0 is for all engines
  {
    switch (state)
    {
      case 0:
        *pinValues = {B00000000};
        sr1.setAll(pinValues);
        sr2.setAll(pinValues);
        break;
      
      case 1:
        *pinValues = {B10101010};
        sr1.setAll(pinValues);
        sr2.setAll(pinValues);
        break;
      
      case 2:
        *pinValues = {B01010101};
        sr1.setAll(pinValues);
        sr2.setAll(pinValues);
        break;
    }
  }
  else if (engine < 5)
  {
    switch (engine)
    {
      
      case 1:
        switch (state)
        {
          case 0:
            sr1.setNoUpdate(0, LOW);
            sr1.setNoUpdate(1, LOW);
            break;
          case 1:
            sr1.setNoUpdate(0, LOW);
            sr1.setNoUpdate(1, HIGH);
            break;
          case 2:
            sr1.setNoUpdate(0, HIGH);
            sr1.setNoUpdate(1, LOW);
            break;
        }
        break;
     
      case 2:
        switch (state)
        {
          case 0:
            sr1.setNoUpdate(2, LOW);
            sr1.setNoUpdate(3, LOW);
            break;
          case 1:
            sr1.setNoUpdate(2, LOW);
            sr1.setNoUpdate(3, HIGH);
            break;
          case 2:
            sr1.setNoUpdate(2, HIGH);
            sr1.setNoUpdate(3, LOW);
            break;
        }
        break;
      
      case 3:
        switch (state)
        {
          case 0:
            sr1.setNoUpdate(4, LOW);
            sr1.setNoUpdate(5, LOW);
            break;
          case 1:
            sr1.setNoUpdate(4, LOW);
            sr1.setNoUpdate(5, HIGH);
            break;
          case 2:
            sr1.setNoUpdate(4, HIGH);
            sr1.setNoUpdate(5, LOW);
            break;
        }
        break;
      
      case 4:
        switch (state)
        {
          case 0:
            sr1.setNoUpdate(6, LOW);
            sr1.setNoUpdate(7, LOW);
            break;
          case 1:
            sr1.setNoUpdate(6, LOW);
            sr1.setNoUpdate(7, HIGH);
            break;
          case 2:
            sr1.setNoUpdate(6, HIGH);
            sr1.setNoUpdate(7, LOW);
            break;
        }
        break;
    }
  }
  else
  {
    switch (engine)
    {
      
      case 5:
        switch (state)
        {
          case 0:
            sr2.setNoUpdate(0, LOW);
            sr2.setNoUpdate(1, LOW);
            break;
          case 1:
            sr2.setNoUpdate(0, LOW);
            sr2.setNoUpdate(1, HIGH);
            lcd.setCursor(10, 1);
            break;
          case 2:
            sr2.setNoUpdate(0, HIGH);
            sr2.setNoUpdate(1, LOW);
            break;
        }
        break;
      
      case 6:
        switch (state)
        {
          case 0:
            sr2.setNoUpdate(2, LOW);
            sr2.setNoUpdate(3, LOW);
            break;
          case 1:
            sr2.setNoUpdate(2, LOW);
            sr2.setNoUpdate(3, HIGH);
            lcd.setCursor(10, 1);

            break;
          case 2:
            sr2.setNoUpdate(2, HIGH);
            sr2.setNoUpdate(3, LOW);
            break;
        }
        break;
     
      case 7:
        switch (state)
        {
          case 0:
            sr2.setNoUpdate(4, LOW);
            sr2.setNoUpdate(5, LOW);
            break;
          case 1:
            sr2.setNoUpdate(4, LOW);
            sr2.setNoUpdate(5, HIGH);
            break;
          case 2:
            sr2.setNoUpdate(4, HIGH);
            sr2.setNoUpdate(5, LOW);
            break;
        }
        break;
     
      case 8:
        switch (state)
        {
          case 0:
            sr2.setNoUpdate(6, LOW);
            sr2.setNoUpdate(7, LOW);
            break;
          case 1:
            sr2.setNoUpdate(6, LOW);
            sr2.setNoUpdate(7, HIGH);
            break;
          case 2:
            sr2.setNoUpdate(6, HIGH);
            sr2.setNoUpdate(7, LOW);
            break;
        }
        break;
    }
  }

  if (noUpdate == true)
  {

    sr1.updateRegisters();
    sr2.updateRegisters();
  }
  f_engine_scale = true;
}



void engine_start()
{
  if (f_engine == true)
  {
    lcd.setCursor(8, 1);
    lcd.print(which_formula);

    if (formulas[which_formula][0] > 0)
    {
      pomp1.begin(formulas[which_formula][0] * ratio); //formulas[which_formula][0]
      engine_choice(1, 1, true);
    }
   
    if (formulas[which_formula][1] > 0)
    {
      pomp2.begin(formulas[which_formula][1] * ratio); //formulas[which_formula][1]
      engine_choice(2, 1, true);
    }
   
    if (formulas[which_formula][2] > 0)
    {
      pomp3.begin(formulas[which_formula][2] * ratio);
      engine_choice(3, 1, true);
    }
    
    if (formulas[which_formula][3] > 0)
    {
      pomp4.begin(formulas[which_formula][3] * ratio);
      engine_choice(4, 1, true);
    }
    if (formulas[which_formula][4] > 0)
    
    {
      pomp5.begin(formulas[which_formula][4] * ratio);
      engine_choice(5, 1, true);
    }
    
    if (formulas[which_formula][5] > 0)
    {
      pomp6.begin(formulas[which_formula][5] * ratio);
      engine_choice(6, 1, true);
    }

    f_engine = false;
    f_engine_start = true;
    lcd.setCursor(9, 1);
    lcd.print("Z");
  }

}

void engine_stop()
{
  if (pomp1.available()) engine_choice(1, 0, true);

  if (pomp2.available()) engine_choice(2, 0, true);

  if (pomp3.available()) engine_choice(3, 0, true);

  if (pomp4.available()) engine_choice(4, 0, true);

  if (pomp5.available()) engine_choice(5, 0, true);

  if (pomp6.available()) engine_choice(6, 0, true);
}
