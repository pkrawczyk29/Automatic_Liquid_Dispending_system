//LoadCell Function

void read_scale()
{
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  reading = scale.get_units(10);
  Serial.print(" g"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.print("  Offset: ");
  Serial.print(offset);
  Serial.print("  Rea: ");
  Serial.print(reading);
  Serial.println();
}

void resest_scale()

{
  read_scale();

  if (reading < 3)
  {
    scale.tare();
    f_engine_scale = false;
    f_engine = false;
    f_glass = false;
    offset = 0;
    which_pomp = 0;
    engine_choice (0, 0, true);
    f_engine_scale = false;
    engine_monitor();
  }

  read_scale();

}

void engine_control_scale()  // Function to organise the pouring in feedback
{
  read_scale();

  if (reading > 10 && f_glass == false)
  {
    delay(1200);
    f_glass = true;
    read_scale();
    offset = reading;
  }

  if (f_glass == true)
  {
    switch (which_pomp)
    {
      case 0:
        if (f_engine_scale == true && reading - offset >= formulas[which_formula][which_pomp])
        {
          engine_choice (which_pomp + 1, 0, true);
          offset = reading;
          which_pomp = which_pomp + 1;
          f_engine_scale = false;
        }
        else if (f_engine_scale == false && formulas[which_formula][which_pomp] > 0) engine_choice (which_pomp + 1, 1, true);
        else if (formulas[which_formula][which_pomp] <= 0) which_pomp = which_pomp + 1;
        break;

      case 1:
        if (f_engine_scale == true && reading - offset >= formulas[which_formula][which_pomp])
        {
          engine_choice (which_pomp + 1, 0, true);
          offset = reading;
          which_pomp = which_pomp + 1;
          f_engine_scale = false;
        }
        else if (f_engine_scale == false && formulas[which_formula][which_pomp] > 0) engine_choice (which_pomp + 1, 1, true);
        else if (formulas[which_formula][which_pomp] <= 0) which_pomp = which_pomp + 1;
        break;

      case 2:
        if (f_engine_scale  == true && reading - offset >= formulas[which_formula][which_pomp])
        {
          engine_choice (which_pomp + 1, 0, true);
          offset = reading;
          which_pomp = which_pomp + 1;
          f_engine_scale = false;
        }
        else if (f_engine_scale  == false && formulas[which_formula][which_pomp] > 0) engine_choice (which_pomp + 1, 1, true);
        else if (formulas[which_formula][which_pomp] <= 0) which_pomp = which_pomp + 1;
        break;

      case 3:
        if (f_engine_scale  == true && reading - offset >= formulas[which_formula][which_pomp])
        {
          engine_choice (which_pomp + 1, 0, true);
          offset = reading;
          which_pomp = which_pomp + 1;
          f_engine_scale = false;
        }
        else if (f_engine_scale == false && formulas[which_formula][which_pomp] > 0) engine_choice (which_pomp + 1, 1, true);
        else if (formulas[which_formula][which_pomp] <= 0) which_pomp = which_pomp + 1;
        break;

      case 4:
        if (f_engine_scale == true && reading - offset >= formulas[which_formula][which_pomp])
        {
          engine_choice (which_pomp + 1, 0, true);
          offset = reading;
          which_pomp = which_pomp + 1;
          f_engine_scale = false;
        }
        else if (f_engine_scale  == false && formulas[which_formula][which_pomp] > 0) engine_choice (which_pomp + 1, 1, true);
        else if (formulas[which_formula][which_pomp] <= 0) which_pomp = which_pomp + 1;
        break;

      case 5:
        if (f_engine_scale == true && reading - offset >= formulas[which_formula][which_pomp])
        {
          engine_choice (which_pomp + 1, 0, true);
          offset = reading;
          which_pomp = which_pomp + 1;
          f_engine_scale = false;
        }
        else if (f_engine_scale  == false && formulas[which_formula][which_pomp] > 0) engine_choice (which_pomp + 1, 1, true);
        else if (formulas[which_formula][which_pomp] <= 0) which_pomp = which_pomp + 1;
        break;

      default:
        resest_scale();
        break;
    }
    if (which_pomp > 5) resest_scale();
  }
}
