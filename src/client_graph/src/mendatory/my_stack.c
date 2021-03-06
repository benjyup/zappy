/*
** my_stack.c for  in /home/kyxo/rendu/Reseau/zappy/PSU_2016_zappy/client/src/mendatory
** 
** Made by Vincent
** Login   <florian.vincent@epitech.eu>
** 
** Started on  Sun Jul  2 22:35:57 2017 Vincent
** Last update Sun Jul  2 22:40:08 2017 Vincent
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mendatory/my_stack.h"

t_stack			*stack_new(t_stack *stack, const char *string)
{
  t_stack		*new;
  t_stack		*idx;

  if (!(new = malloc(sizeof(t_stack))))
    return (perror("malloc()"), NULL);
  new->data = strdup(string);
  new->ptr = new->data;
  new->next = NULL;
  if (!stack)
    {
      stack = new;
      return (stack);
    }
  idx = stack;
  while (idx->next)
    idx = idx->next;
  idx->next = new;
  return (stack);
}

t_stack			*stack_delete(t_stack *stack)
{
  t_stack		*ref;

  if (!stack)
    return (NULL);
  ref = stack;
  stack = stack->next;
  if (ref->data)
    free(ref->data);
  free(ref);
  return (stack);
}

t_stack			*stack_flush(t_stack *stack)
{
  while (stack != NULL)
    stack = stack_delete(stack);
  return (NULL);
}
