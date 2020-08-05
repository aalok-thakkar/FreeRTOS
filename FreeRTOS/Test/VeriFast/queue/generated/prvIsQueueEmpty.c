static BaseType_t prvIsQueueEmpty( const Queue_t * pxQueue )
/*@requires [1/2]queuehandle(pxQueue, ?N, ?M, ?is_isr) &*& is_isr == false;@*/
/*@ensures [1/2]queuehandle(pxQueue, N, M, is_isr);@*/
{
    BaseType_t xReturn;

    taskENTER_CRITICAL();
    /*@assert queue(pxQueue, ?Storage, N, M, ?W, ?R, ?K, ?is_locked, ?abs);@*/
    {
        if( pxQueue->uxMessagesWaiting == ( UBaseType_t ) 0 )
        {
            xReturn = pdTRUE;
        }
        else
        {
            xReturn = pdFALSE;
        }
    }
    /*@close queue(pxQueue, Storage, N, M, W, R, K, is_locked, abs);@*/
    taskEXIT_CRITICAL();

    return xReturn;
}

