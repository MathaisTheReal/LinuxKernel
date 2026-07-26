#include ".h"
#include "linux.slab.h"
#include "linux.uacess.h"
#include <stdlib.h>
#include <string.h>
#include/uapi/asm-generic/errno.h
#include/uapi/asm-generic/errno-base.h
include/linux/irqflags.h

typedef struct _msg_t msg_t;

struct _msg_t{
  msg_t* previous;
  int length;
  char* message;
};

static msg_t *top = NULL;

int custom_msgbox_put( char *buffer, int length ) {
  if(sizeof(buffer) != sizeof(msg->message)
  {
  return -2
  }
  if((length) != (msg->length)
  {
  return -2
  }
  
  
  if(access_ok(buffer, length) != 0)
  {
  return -2
  }
  
  msg_t* msg = kmalloc(sizeof(msg_t), );
  // needs eroor handing with errno.h or .base
  msg->previous = NULL;
  msg->length = length;
  msg->message = kmalloc(length, );
  copy_from_user(buffer, msg->message, length)
  // needs eroor handing with errno.h or .base

  


  if (top == NULL) {
    top = msg;
  } else {
    /* not empty stack */
    msg->previous = top;
    top = msg;
  }
    kfree(msg->message);
    kfree(msg);
    return 0;

}

int custom_msgbox_get( char* buffer, int length ) {
  if (top != NULL) {
    msg_t* msg = top;
    int mlength = msg->length;
    top = msg->previous;
    if (length < mlength) {
      return -2;
    }
    if(sizeof(buffer) != sizeof(msg->message)
  {
  return -2;
  } 
  copy_to_user(buffer, msg->message, length);
    /* copy message */
    // implec acess_()
    // impelce copy from user and to user

    /* free memory */
    kfree(msg->message);
    kfree(msg);

    return mlength;
  }
  return -1;


}
