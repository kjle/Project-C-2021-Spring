#include"data.h"
#include"init.h"

/*
 Function: Calculate the number of lives.
 */
void lifeGameData(void)
{
    int maxN = winWidth / sqarePixel;
    int maxM = winHeight / sqarePixel;
    int storage[maxN + 2][maxM + 2];
    int live = 0;

    /* In accordance with the rule of the LifeGame */
    for(int i = 0; i < maxN; i++)
        for(int j = 0; j < maxM; j++)
        {
            for(int q = i - 1; q <= i + 1; q++)
                for(int k = j - 1; k <= j + 1; k++)
                {
                  if(q==i&&k==j) continue;
                    int X = (q < 0) ? (maxN + q) : q;
                    X = (q >= maxN) ? (q - maxN) : X;
                    int Y = (k < 0) ? (maxM + k) : k;
                    Y = (k >= maxM) ? (k - maxM) : Y;
                    if(lifeGame[X][Y]) live++;
                }


            if(lifeGame[i][j])
            {
                if(live == 2 || live == 3) storage[i][j] = 1;
                else
                    storage[i][j] = 0;
            }

            if(lifeGame[i][j] == 0)
            {
                if(live == 3) storage[i][j] = 1;
                else
                    storage[i][j] = 0;
            }
          live=0;
        }

    /* Update lifeGame[][] from the temporary data storage[][]*/
    for(int i = 0; i < maxN; i++)
        for(int j = 0; j < maxM; j++)
            lifeGame[i][j] = storage[i][j];

    return;
}

/*
 Function: Calculate the number of lives.
 */
void DayAndNightData(void)
{
    int maxN = winWidth / sqarePixel;
    int maxM = winHeight / sqarePixel;
    int storage[maxN + 2][maxM + 2], live = 0;

    /* In accordance with the rule of the DayAndNight */
    for(int i = 0; i < maxN; i++)
        for(int j = 0; j < maxM; j++)
        {
          
            for(int q = i - 1; q <= i + 1; q++)
                for(int k = j - 1; k <= j + 1; k++)
                {
                  if(q==i&&k==j) continue;
    
                     int X = ((q < 0) ? (maxN + q) : q);
                     X = ((q >= maxN) ? (q - maxN) : X);
                    int Y = (k < 0) ? (maxM + k) : k;
                    Y = (k >= maxM) ? (k - maxM) : Y;
                    if(X<0||X>=maxN) printf("ERROR");
                    if(dayAndNight[X][Y]) live++;
                }

            if(dayAndNight[i][j] == 0)
            {
                if(live == 3 || live == 6 || live == 7 || live == 8)
                    storage[i][j] = 1;
                else
                    storage[i][j] = 0;
            }
            else
            {
                if(live == 3 || live == 4 || live == 6 || live == 7 || live == 8)
                    storage[i][j] = 1;
                else
                    storage[i][j] = 0;
            }
            live=0;
        }

    /* Update dayAndNight[][] from the temporary storage storage[][]*/
    for(int i = 0; i < maxN; i++)
        for(int j = 0; j < maxM; j++)
            dayAndNight[i][j] = storage[i][j];

    return;
}
