/* Cave 2 v0.2
 * Cave with corridors, ninjas and one exit game.
 * More rooms than in first game.
 * Author: Kurashov Artem
 * License: GNU GPLv3
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int
get_random (int g_rand_max)
{
  return (int) ((g_rand_max + 1.0) * rand () / (RAND_MAX + 1.0));
}

int main ()
{
  int i, j, sr, fr, h = 6, cr[5][32];
  srand (time (0));
  for (i = 0; i < 5; i++)
    for (j = 0; j < 32; j++)
      cr[i][j] = get_random (31);
  sr = get_random (31);
  while ((fr = get_random (31)) == sr);
  for (;;)
    {
      printf ("current room #%d, health: %d\n", sr, h);
      if (sr == fr)
	{
	  printf ("U found exit! Congratulation! The end.\n");
	  return 0;
	}
      if (cr[0][sr] < 10)
	{
	  printf ("U attacked by ninja!...\n");
	  if (--h == 0)
	    {
	      printf ("U die... Game Over...\n");
	      return 0;
	    }
	}
      printf ("%d corridors here. choose one (1-%d):", 1 + cr[4][sr] / 11,
	      1 + cr[4][sr] / 11);
      do
	{
	  scanf ("%1d", &i);
	  getchar();
	}
      while (i < 1 || i > 1 + cr[4][sr] / 11);
      sr = cr[i][sr];
    }
}
