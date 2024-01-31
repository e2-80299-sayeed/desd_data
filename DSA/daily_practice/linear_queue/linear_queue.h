#define SIZE 5
typedef struct queue
{
    int arr[SIZE];
    int front;
    int rear;
}queue;

void init_queue(queue *pq);
void enqueue(queue *pq, int data);
void dequeue(queue *pq);
int queue_empty(queue *pq);
int queue_full(queue *pq);
int get_front(queue *pq);