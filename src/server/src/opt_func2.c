/*
** opt_func2.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_zappy/src/server/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Jun 20 14:31:23 2017 Gregoire Renard
** Last update Wed Jun 21 14:40:08 2017 Gregoire Renard
*/

#include "server.h"

int		count_len(char **argv, int cpt)
{
  int		save;

  save = cpt;
  while (argv[cpt] != NULL)
    {
      if (argv[cpt][0] == '-')
	return (cpt - save);
      cpt++;
    }
  return (cpt - save);
}

int		opt_n(t_env *env,
		      char **argv,
		      int *cpt)
{
  int		len;
  int		cpt_name;
  
  *cpt = *cpt + 1;
  cpt_name = 0;
  len = count_len(argv, *cpt);
  env->arg.nb_team = len;
  if ((env->arg.team = malloc(sizeof(t_team) * (len))) == NULL)
    return (ERROR);
  while (cpt_name != len)
    {
      if ((env->arg.team[cpt_name].team_name = strdup(argv[*cpt])) == NULL)
	return (ERROR);
      env->arg.team[cpt_name].nb_player = 0;
      cpt_name++;
      *cpt = *cpt + 1;
    }
  return (SUCCESS);
}

int		opt_c(t_env *env,
		      char **argv,
		      int *cpt)
{
  if (argv[(*cpt) + 1] == NULL)
    return (ERROR);
  if ((check_alpha(argv[(*cpt) + 1])) == ERROR)
    return (ERROR);
  env->arg.clients_lim = atoi(argv[(*cpt) + 1]);
  if (env->arg.clients_lim <= 0)
    return (ERROR);
  *cpt = *cpt + 2;
  return (SUCCESS);
}

int		opt_f(t_env *env,
		      char **argv,
		      int *cpt)
{
  if (argv[(*cpt) + 1] == NULL)
    return (ERROR);
  if ((check_alpha(argv[(*cpt) + 1])) == ERROR)
    return (ERROR);
  env->arg.freq = atoi(argv[(*cpt) + 1]);
  if (env->arg.freq <= 0)
    return (ERROR);
  *cpt = *cpt + 2;
  return (SUCCESS);
}
