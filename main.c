#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE 1

pthread_mutex_t mutex;
sem_t full, empty;
int in = 0, out = 0;
int *buffer;
int x = 0;
int n, b;

void *producer(void *);
void *consumer(void *);

int main(void) {

	int p, c;
	scanf("%d %d %d %d", &p, &c, &n, &b);

	buffer = malloc(b * sizeof(int));
	int producers_ids[p], consumers_ids[c];

	for (int i = 0; i < b; i++) buffer[i] = 0;
	for (int i = 0; i < p; i++) producers_ids[i] = i;
	for (int i = 0; i < c; i++) consumers_ids[i] = i;

	pthread_mutex_init(&mutex, NULL);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, b);

	pthread_t producers[p], consumers[c];

	for (int i = 0; i < p; i++)
		pthread_create(&producers[i], NULL, producer, &producers_ids[i]);
	
	for (int j = 0; j < c; j++)
		pthread_create(&consumers[j], NULL, consumer, &consumers_ids[j]);

	for (int i = 0; i < p; i++)
		pthread_join(producers[i], NULL);

	for (int j = 0; j < c; j++)
		pthread_join(consumers[j], NULL);

	return 0;
}	

void *producer(void *args) {
	int *producer_id = (int *) args;

	while (TRUE) {
		int y = 2 * x + 1;

		sem_wait(&empty);

		pthread_mutex_lock(&mutex);

		if (buffer[in % b] == 0) {
			printf("Produtor %d produzindo %d na posicao %d\n", *producer_id, y, in % b);
			buffer[in % b] = y;
			x++;
		}
		in++;

		if (x > n)
			x = 0;

		pthread_mutex_unlock(&mutex);

		sem_post(&full);
	}
}

void *consumer(void *args) {
	int *consumer_id = (int *) args;
	
	while (TRUE) {
		sem_wait(&full);

		pthread_mutex_lock(&mutex);

		if (!(buffer[out % b] == 0)) {
			printf("Consumidor %d consumindo %d na posicao %d\n", *consumer_id, buffer[out % b], out % b);
			buffer[out % b] = 0;
		}
		out++;

		pthread_mutex_unlock(&mutex);

		sem_post(&empty);
	}
}
