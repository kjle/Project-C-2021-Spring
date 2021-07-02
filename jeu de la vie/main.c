#include "vue.h"
#include "init.h"
#include "data.h"

int main(int argc, char **argv)
{
  /* Initiate everything with libsx */
  argc = OpenDisplay(argc, argv);
    
  if (argc!=1)                  
    exit(EXIT_FAILURE);
  
    /* Initiate display with libsx */
  init_display();
  ShowDisplay();
  
  GetStandardColors();

  MainLoop();  

    EXIT_SUCCESS;
}
