//Function to fill the table witch formulas


//Tab with amount of ml. of drink
unsigned short int formulas[7][6];

void fill_formulas()
{
  // Przepis 1
  formulas[0][0] = 20;
  formulas[0][1] = 0;
  formulas[0][2] = 0;
  formulas[0][3] = 0;
  formulas[0][4] = 5;
  formulas[0][5] = 0;

  // Przepis 2
  formulas[1][0] = 0;
  formulas[1][1] = 20;
  formulas[1][2] = 0;
  formulas[1][3] = 0;
  formulas[1][4] = 0;
  formulas[1][5] = 0;

  // Przepis 3
  formulas[2][0] = 0;
  formulas[2][1] = 0;
  formulas[2][2] = 20;
  formulas[2][3] = 0;
  formulas[2][4] = 15;
  formulas[2][5] = 0;

  // Przepis 4
  formulas[3][0] = 0;
  formulas[3][1] = 0;
  formulas[3][2] = 0;
  formulas[3][3] = 20;
  formulas[3][4] = 0;
  formulas[3][5] = 0;

  // Przepis 5
  formulas[4][0] = 0;
  formulas[4][1] = 0;
  formulas[4][2] = 0;
  formulas[4][3] = 0;
  formulas[4][4] = 20;
  formulas[4][5] = 10;

  // Przepis 6 - user_choice
  formulas[5][0] = 0;
  formulas[5][1] = 0;
  formulas[5][2] = 0;
  formulas[5][3] = 0;
  formulas[5][4] = 0;
  formulas[5][5] = 0;

  // Przepis 7 - czyszczenie
  formulas[6][0] = 10;
  formulas[6][1] = 10;
  formulas[6][2] = 10;
  formulas[6][3] = 10;
  formulas[6][4] = 10;
  formulas[6][5] = 10;
}
