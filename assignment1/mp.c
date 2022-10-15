#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	if(where==-1)
	{	insert_front(playlist->list,song_id);
		playlist->num_songs++;
	}
	if(where==-2)
	{	insert_back(playlist->list,song_id);
		playlist->num_songs++;
	}
	else
	{
		insert_after(playlist->list,song_id,where);
		playlist->num_songs++;
	}
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
	delete_node(playlist->list,song_id);
	playlist->num_songs--;
	
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	song_t *node;
	node=search(playlist->list,song_id);
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	song_t *node;
	node=search(playlist->list,song_id);
	//playlist->last_song=node;
	if(node==NULL)
		return;
	else
		play_song(node->data);
}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
	if(q->front==NULL)
	{
		if(playlist->last_song!=NULL)
		{
			if(playlist->last_song==playlist->list->tail)
			{
				play_song(playlist->list->head->data);
				playlist->last_song=playlist->list->head;
			}
			else
			{
				play_song(playlist->last_song->next->data);
				playlist->last_song=playlist->last_song->next;
			}
		}
		else
		{
			play_song(playlist->list->head->data);
			playlist->last_song=playlist->list->head;
		}
	}
	if(playlist->list==NULL)
	{
		return;
	}
	if(q->front!=NULL)
	{
		int num;
		song_t *temp;
		num=dequeue(q);
		temp=search(q->list,num);
		play_song(temp->data);
	}
}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	if(playlist->last_song==NULL)
	{
		if(playlist->last_song==playlist->list->tail)
		{
			play_song(playlist->list->tail->data);
			playlist->last_song=playlist->list->tail;
		}
		else
		{
			play_song(playlist->last_song->prev->data);
			playlist->last_song=playlist->last_song->prev;
		}
	}
	else
	{
		play_song(playlist->list->tail->data);
		playlist->last_song=playlist->list->tail;
	}
	
}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
	song_t *temp;
	int num;
	num=dequeue(q);
	temp=search(q->list,num);
	play_song(temp->data);//DOUBT!!!!!
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q,song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	song_t *temp,*phead,*ptail;
	phead=playlist->list->head;
	ptail=playlist->list->tail;
	temp=playlist->list->tail;
	if (playlist->list->head==NULL)
		return;
	else
	{
		while(temp->prev!=NULL)
		{
			//printf("in next\n");
			temp->next=temp->prev;
			temp=temp->prev;
			if(temp==phead)
			{temp->next=NULL;}
			//printf("set to null\n");}
		}
		temp=playlist->list->tail;
		//printf("tail(temp):%d\n",playlist->list->tail->data);
		//if(playlist->list->head->next==NULL)
			//printf("tail to null\n");
		while(temp->next!=NULL)
		{
			//printf("in prev\n");
			temp->next->prev=temp;
			//printf("TEMP:%d\n",temp->data);
			temp=temp->next;
			if(temp==ptail)
				temp->prev=NULL;
			
		}
		playlist->list->head=playlist->list->tail;
		playlist->list->tail=phead;
	}
	
	
	
	/*song_t *temp,*phead,*past;
	phead=playlist->list->head;
	temp=playlist->list->tail;
	past=temp->prev;
	//printf("in reverse\n");
	while(temp!=phead)
	{
		temp->next=past;
		//printf("in while(r)\n");
		if(temp==playlist->list->tail)
		{
			temp->prev=NULL;
			//printf("when temp=tail\n");
		}
		past=temp->next->prev;
		//printf("temp->next:%d\n",temp->next->data);
		temp->next->prev=temp;
		temp=temp->next;
    }
	temp->next=NULL;
	playlist->list->head=playlist->list->tail;
	playlist->list->head=temp;*/
	
 
	
}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	int i=0;
	song_t *temp,*current,*first,*second;
	current=playlist->list->head;
	printf("initial CURRENT:%d\n",current->data);
	//temp=playlist->list->head;
	printf("size:%d\n",playlist->num_songs);
		
	while((i+k<playlist->list->size))
	{
		int count=0;
		temp=playlist->list->head;
		first=current;
		temp=current;
		while(count!=k)
		{
			second=temp;
			temp=temp->next;
			count++;
		}
		if(i+k==count)
		{
			song_t *fn,*sp;
			second=second->next;
			fn=first->next;
			sp=second->prev;
			//printf("first:%d second:%d\n",first->data,second->data);
			//printf("k=%d fn:%d sp:%d\n",k,fn->data,sp->data);
			
			if(first->prev!=NULL)
			{first->prev->next=second;}
			//printf("first->prev->next:%d\n",first->prev->next->data);}
			if(second->next!=NULL)
			{second->next->prev=first;}
			//printf("second->next->prev:%d\n",second->next->prev->data);}
			
			first->next=second->next;
			//printf("first->next:%d\n",first->next->data);
			second->prev=first->prev;
			//printf("second->prev:%d\n",second->prev->data);
			if(k==1)
			{
				first->prev=second;
				second->next=first;
			}
			if(k!=1)
			{
				//printf("k not 1\n");
				first->prev=sp;
				//printf("first->prev:%d\n",first->prev->data);
				second->next=fn;
				//printf("second->next:%d\n",second->next->data);
				fn->prev=second;
				//printf("fn->prev:%d\n",fn->prev->data);
				sp->next=first;
				//printf("sp->next:%d\n",sp->next->data);
			}
			if(first==playlist->list->head)
				//printf("allocating head\n");
				{playlist->list->head=second;
				current=playlist->list->head;
				printf("head value:%d\n",playlist->list->head->data);}
			printf("CURRENT:%d\n",current->data);
		}
		
		i++;
		printf("i:%d\n",i);
		current=current->next;
		printf("current:%d\n",current->data);		
	}
	song_t *temph,*templ;
	temph=playlist->list->head;
	while(temph->next!=NULL)
		temph=temph->next;
	//printf("last:%d\n",temph->data);
	//templ=temph;
	playlist->list->tail=temph;
	//printf("tail:%d\n",playlist->list->tail->data);
}

void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	k_swap(playlist,k);
	//reverse(playlist);
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	song_t* temp;
	temp=playlist->list->tail->next;
	return temp;
}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}


