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
	{
		insert_front(playlist->list,song_id);
	}
	else if(where==-2)
	{
		insert_back(playlist->list,song_id);
	}
	else
	{
		insert_after(playlist->list,song_id,where);
	}
	playlist->num_songs+=1;
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
	delete_node(playlist->list,song_id);
	playlist->num_songs-=1;
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	song_t* song=search(playlist->list,song_id);
	return song;
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	song_t* s=search_song(playlist,song_id);
	if(s!=NULL)
	{
		playlist->last_song=s;
		play_song(song_id);
	}

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
	else
	{
		play_from_queue(q);
	}

}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	if(playlist->last_song!=NULL)
	{
		if(playlist->last_song==playlist->list->head)
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
	int s=dequeue(q);
	play_song(s);
	
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q,song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	song_t* dtail=playlist->list->tail;
	song_t* dhead=playlist->list->head;
	song_t* temp;
	temp=dtail->prev;
	while(dtail!=dhead)
	{
		dtail->next=temp;
		if(dtail==playlist->list->tail)
		{
		dtail->prev=NULL;
		}
		temp=dtail->next->prev;
		dtail->next->prev=dtail;
		dtail=dtail->next;
	}
	dtail->next=NULL;
	playlist->list->head=playlist->list->tail;
	playlist->list->tail=dhead;
}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{

	song_t* ptr1,*ptr2;
	ptr1=ptr2=playlist->list->head;
	for(int i=0;i+k<playlist->list->size;i++)
	{
		ptr1=ptr2=playlist->list->head;
		for(int j=0;j<i;j++)
		{
			ptr1=ptr1->next;
		}
		for(int x=0;x<(i+k);x++)
		{
			ptr2=ptr2->next;
	        }
			
		if(k!=1)
		{
			song_t* t1,*t2;
			t1=ptr1->next;
			t2=ptr2->prev;
			ptr1->next=ptr2->next;
			if(ptr2->next!=NULL)
				ptr2->next->prev=ptr1;
			ptr2->next=t1;
			ptr2->prev=ptr1->prev;
			if(ptr2->prev!=NULL)
				ptr2->prev->next=ptr2;
			t1->prev=ptr2;
			t2->next=ptr1;
			ptr1->prev=t2;
			if(ptr2->prev==NULL)
				playlist->list->head=ptr2;
			if(ptr1->next==NULL)
				playlist->list->tail=ptr1;
		}
		else
		{
			ptr1->next=ptr2->next;
			if(ptr2->next!=NULL)
				ptr2->next->prev=ptr1;
			ptr2->prev=ptr1->prev;
			if(ptr2->prev!=NULL)
				ptr2->prev->next=ptr2;
			ptr2->next=ptr1;
			ptr1->prev=ptr2;
			if(ptr2->prev==NULL)
				playlist->list->head=ptr2;
			if(ptr1->next==NULL)
				playlist->list->tail=ptr1;
		}
	}
}

void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	k_swap(playlist,k);
	reverse(playlist);
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	song_t* dhead;
	dhead=playlist->list->head;
	while(dhead!=NULL)
	{
		if(dhead->next!=NULL)
		{
		if(dhead->next->prev!=dhead)
		{
			return dhead->next;
		}
		}
		dhead=dhead->next;
		
	}
	return NULL;
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

