#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct s_cmd
{
	char **argv;
	int in;
	int out;
	struct s_cmd *next;
}		t_cmd;

t_cmd *cmd;

int main(int ac,char **av,char**env)
{
	int i = 0;
	int fd[2];
	t_cmd *tmp;
	int	in = 0;
	int	pid;
	char *tmp2;
	tmp = cmd;
	while (tmp)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			if (i != 0)
				dup2(in, 0);
			if (tmp->next != NULL)
				dup2(fd[1], 1);
			//search and execute
			tmp2 = finder(env, tmp->argv[0]);
			//handle errors
			if (tmp2 == NULL)
				printf("%s: command not found\n", tmp->argv[0]);
			if (!execve(tmp2, tmp->argv, env))
				print("execve failed\n");
			// child must always exit
		} 
		i++;	
		tmp = tmp->next;
		if (i != 0)
			close(in);
		in = fd[0];
		close(fd[1]);
	}
	waitpid(pid, NULL, 0);
	while (wait(NULL));
	//get execstatus with macros;
}
