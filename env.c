#include "holberton.h"

/**
 * set_env - sets an env variable.
 * @cmd: command.
 * @env: struc of env variables.
 * Return: nothing.
 */


int set_env(char **cmd, env_t *env)
{

	est_env *nodescanner = env->env_var;
	char *var, *value, *node;


	var = cmd[1];
	value = cmd[2];


	if (env && value)
	{
		if (!nodescanner)
		{
			addnode(&env->env_var, var, value);
			return;
		}

		while (nodescanner)
		{
			node = (nodescanner->envar);

			if (!_strcmp(var, node))
				(nodescanner->value) = value;

			nodescanner = (nodescanner->next);
		}

		if (!nodescanner && _strcmp(var, node))
		    addnode(&(env->env_var), var, value);
	}
	else
	{
		env->status = -1;
		write(STDERR_FILENO, "Invalid Argument\n", 17);
	}

/**
	reverse_list(&(env->env_var));
**/
	return (0);
}

/**
 * addnode - adds node at end of linked list.
 * @head: env variables linked list.
 * @var: variable to be set.
 * @value:  value of variable.
 * Return: nothing.
 */


void addnode(est_env **head, char *var, char *value)
{

        est_env  *node, *end;

        node = malloc(sizeof(est_env));


        if (node)

        {
                node->envar = NULL;
                node->value = NULL;
		node->next = NULL;

                if (var && value)
                {
                        node->envar = strdup(var);
                        if (!node->envar)
			{
                                free(node);
                                return;
                        }
			node->value = strdup(value);
			if (!node->envar)
                        {
				free(node->envar);
                                free(node);
                                return;
                        }
                }

                else
		{
                        node->envar = NULL;
			node->value = NULL;
		}

	}

     if (*head)
        {
                end = *head;
                while (end->next)
                        end = end->next;
                end->next = node;
        }
        else

                *head = node;
}

/**
 * print_list - prints linked list.
 * @h: pointer to linked list.
 * Return: nothing.
 */

void print_list(env_t *env)
{
	est_env *h = env->env_var;

	int i;

        while (h)
        {
                if (h->envar)
		{


			for (i = 0; h->envar[i] != '\0'; i++)
				_putchar(h->envar[i]);

			_putchar('=');

			for (i = 0; h->value[i] != '\0'; i++)
				_putchar(h->value[i]);

			_putchar('\n');
		}

                else
                        write(STDERR_FILENO, "CANNOT PRINT SETENV VAR\n", 25);

                h = h->next;

        }

}
/**
 * reverse_list - reverses linked list.
 * @head: pointer to end of list.
 * Return: Nothing.
 */
void reverse_list(est_env **head)
{
        est_env *next, *prevnode = NULL;



        while (*head)
        {


                next = (*head)->next;

                (*head)->next = prevnode;

                prevnode = *head;

                *head = next;

        }

        *head = prevnode;
}