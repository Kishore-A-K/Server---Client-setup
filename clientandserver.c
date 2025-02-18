#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){
	int pipefd[2];
	pid_t pid;
	int numbers[2],sum;

	//pip = o success, pipe =-1 error
	if(pipe(pipefd)== -1){
		printf("error in creating pipe existing\n");
		exit(1);
	}

	for (int i = 0; i<3;i++){
		pid = fork();

		if (pid < 0){
			perror("Error in creating process\n");
			exit(-1);
		}

		if(pid == 0){

			printf("Client %d: Enter two no: \n",i+1);
			scanf("%d %d",&numbers[0],&numbers[1]);

			write(pipefd[1], numbers, sizeof(numbers));
			close(pipefd[1]);

			exit(0);
		}
		wait(NULL);
	}

	close(pipefd[1]);
	for (int i = 0;i<3;i++){
		wait(NULL);
		read(pipefd[0],numbers,sizeof(numbers));
		sum = numbers[0] + numbers[1];
		printf("Server:client %d sent number %d,%d and sum is %d\n",i,numbers[0],numbers[1],sum);
	}
	close(pipefd[1]);
	return 0;
}
