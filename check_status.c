#include "main.h"
/**
 * check_status - read the status of child proccess
 * @pidC: child PID
 * @status: exit status of child
 * Return: -1 if waitpid fails, otherwhise exit status
 */
int check_status(int pidC, int *status)
{
	pid_t w = 0;

	w = waitpid(pidC, status, 0); /*El 0 espera el proceso hijo con el pidC*/

	if (w == -1)
		return (-1)
	if (WIFEXITED(status)) /*Si termina normal, retorna el exit status del child*/
		return (WEXISTATUS(*status));
	else if (WIFSIGNALED(status))/*Si el child fue terminado por una señal retorna el numero de esa señal*/
		return(WTERMSIG(*status));
	else if (WIFSTOPPED(status))/*Si el child fue detenido por una señal retorna el numero de la señal*/
		return(WSTOPSIG(*status));
	return (0);

}
