#include "holberton.h"

/**
 * unset_env - unsets an env varable.
 * @cmd: command.
 * @env: struc of env variables.
 */

int unset_env(char **cmd, env_t *env)
{
	est_env *nodescanner = env->env_var;
	char *var, *node;

	var = cmd[1];

	if (env && var && !cmd[2])
		return (deletenode(&env->env_var, var));


	else if(!cmd[1])
	{
		write(STDERR_FILENO, "ARGUMENT ERROR\n", 15);
		env->status = -1;
	}

	else
        {
                env->status = -1;
                write(STDERR_FILENO, "Invalid Argument\n", 17);
        }

	return (0);

}



unsigned int sortlist(est_env **list, char *cmd)
{
        unsigned int index = 0;

        est_env *currentnode = *list, *next = *list;

        while (next && _strcmp(cmd, currentnode->envar))
        {
                currentnode = next;
                next = next->next;
                index++;
        }

        if (!next)
        {
                write(STDERR_FILENO, "VARIABLE NOT PREV SET\n", 23);
		return;
        }

        return (index);
}



/**
 * deletenode - adds node at end of linked list.
 * @head: env variables linked list.
 * @var: variable to be set.
 * @value:  value of variable.
 * Return: nothing.
 */


int deletenode(est_env **head, char *var)
{
	unsigned int index, idx = 0;
	est_env *nodescanner = *head, *prevnode = *head, *targetnode;

	index = sortlist(head, var);


	if (!*head)
                return (0);

        if (index == 0)
        {

                *head = nodescanner->next;
                free(nodescanner);
                return (1);
        }
        while (nodescanner)
	{
		if ((idx + 1) == index)
			break;

                idx++;
		prevnode = nodescanner;
                nodescanner = nodescanner->next;

        }


        if ((idx + 1) == index)
        {

                targetnode = nodescanner;
                prevnode->next = targetnode->next;
                free(targetnode);

                return (1);
        }

	return (0);
}
