#include "main.h"

/**
 * fork_launch - Forks and launches unix cmd
 * @args: Args for cmd
 * Return: 1 on success
 */
int fork_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Failed to execute command\n");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking\n");
		exit(0);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	(void)wpid;
	return (1);
}
