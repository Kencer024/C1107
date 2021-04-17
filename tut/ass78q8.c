//printLL
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   int i;

   ListNode *temp1;

   for(i=0;i<=C;i++)
   {
       insertNode(ll, i, (i+1));
       printf("i is %d\n",i);
   }

   temp1 = ll->head;
   for(i=1;i<=C;i++)    //from 1 to 6
   {

       printf("ll is %d\n",temp1->item);
       temp1 = temp1->next;

   }

}


//sum checking
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   int i, i2;

   ListNode *temp1, *pre;

   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, i, (i+1));
       i2 = i;
       printf("i is %d\n",i);
       while(ll->sum<C)
       {
           i2++;
           insertNode(ll, i2, (i2+1));
           if(ll->sum == C)
            break;
       }
       printf("sum is %d\n", ll->sum);
   }

   temp1 = ll->head;
   pre = temp1;

}


//sum part 2, correct breaking sum
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0;

   ListNode *temp1, *pre;

   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, ll->size, (i+1));
       i2 = i;
       printf("i is %d\n",i);
       while(ll->sum<C)
       {
           i2++;
           insertNode(ll, ll->size, (i2+1));
           printf("i2 is %d\n",i2);
           if(ll->sum == C)
            break;
       }
       printf("sum is %d\n", ll->sum);
       if(ll->sum == C)
       {
           n++;
       }
       removeNode(ll,ll->size-1);
       removeNode(ll,ll->size-1);
   }

   printf("no of times sum == C is %d\n",n);

}

//sum checking part 3
//got most combi except that it counts 6 multiple times
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2;


   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, ll->size, (i+1));
       temp1 = ll->head;
       i2 = i;
       //printf("i is %d\n",i);
       j2 =i2;
       while(i2 != C)
       {
           i2 = j2;
           if(i2 == C)
           {
               break;
           }
           while(ll->sum<C)
           {
               i2++;
               insertNode(ll, ll->size, (i2+1));
               //printf("i2 is %d\n",i2);

               if(ll->sum == C)
                break;
           }
           printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;
       }
       removeNode(ll,ll->size-1);

   }        //end for

   printf("no of times sum == C is %d\n",n);


}

//sum checking part 4
//100% correct ?
//Apparently not for 9
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2;


   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, ll->size, (i+1));
       temp1 = ll->head;
       i2 = i;
       //printf("i is %d\n",i);
       j2 =i2;
       while(i2 != C)
       {
           i2 = j2;

           //printf("i2 is %d\n",i2);

           if(i2 == C)
           {
               break;
           }

           while(ll->sum<C)
           {
               i2++;
               if(((i2+1) == C) && (i != C))
               {
                   break;
               }
               insertNode(ll, ll->size, (i2+1));
               //printf("i2 is %d\n",i2);

               if(ll->sum == C)
                break;
           }
           //printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;



       }
       removeNode(ll,ll->size-1);

   }        //end for

   printf("no of times sum == C is %d\n",n);


}


//sum check part 5
//realised j should be equal to findNode but cant seem to get syntax right
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2, *temp3;


   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, ll->size, (i+1));
       temp1 = ll->head;
       i2 = i;
       //printf("i is %d\n",i);
       j2 =i2;
       while(i2 != C)
       {
           i2 = j2;

           printf("j2 is %d\n",j2);

           if(i2 == C)
           {
               break;
           }

           while(ll->sum<C)
           {
               i2++;
               if(((i2+1) == C) && (i != C))
               {
                   temp3 = findNode(*ll, (ll->size-2));
                   j = temp3->item;                   //j = the 2 node back item
                   break;
               }
               insertNode(ll, ll->size, (i2+1));
               //printf("i2 is %d\n",i2);

               if(ll->sum == C)
               {
                   temp3 = findNode(*ll,ll->size-2);
                   j = temp3->item;                   //j = the 2 node back item
                   break;
               }

           }
           //printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;



       }
       removeNode(ll,ll->size-1);

   }        //end for

   //printf("no of times sum == C is %d\n",n);


}

//for fxing the j part
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i,n;

   ListNode *temp1,*temp2;

   for(i=0;i<C;i++)
   {
       insertNode(ll, i, (i+1));
       printf("i is %d\n",i);
   }

    temp1 = ll->head;
   for(i=1;i<=C;i++)    //from 1 to 6
   {

       printf("ll is %d\n",temp1->item);
       temp1 = temp1->next;

   }
    n = ll->size;
    printf("n is %d\n",n);
   temp2 = findNode(*ll, n-3);
   printf("temp item is %d\n",temp2->item);




}


//sum checking part 6
//fixed syntax but traversal algo got prob
//i2++ when its supposed to be 3
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2, *temp3;


   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, ll->size, (i+1));
       temp1 = ll->head;
       i2 = i;
       //printf("i is %d\n",i);
       j2 =i2;
       while(i2 != C)
       {

            i2 = j2;
           //printf("j2 is %d\n",j2);

           if(i2 == C)
           {
               break;
           }

           while(ll->sum<C)
           {
               i2++;
               if(((i2+1) == C) && (i != C))        //for the multiple 6
               {

                   break;
               }

               insertNode(ll, ll->size, (i2+1));
               //printf("j2 is %d\n",j2);

               if(ll->sum == C)
               {
                   temp3 = findNode(*ll,ll->size-2);
                   j2 = temp3->item;                   //j = the 2 node back item
                   break;
               }

           }
           //printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;



       }
       removeNode(ll,ll->size-1);

   }        //end for

   //printf("no of times sum == C is %d\n",n);


}


//sum check extra
//doing this will give 3 3 also for 6
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2, *temp3;


   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, ll->size, (i+1));
       temp1 = ll->head;
       i2 = i;
       //printf("i is %d\n",i);
       j2 =i2;
       while(i2 != C)
       {

            i2 = j2;
           //printf("j2 is %d\n",j2);

           if(i2 == C)
           {
               break;
           }

           while(ll->sum<C)
           {

               if(((i2+1) == C) && (i != C))        //for the multiple 6
               {

                   break;
               }

               insertNode(ll, ll->size, (i2+1));
               //printf("i2 is %d\n",i2);

               if(ll->sum == C)
               {
                   temp3 = findNode(*ll,ll->size-2);
                   j2 = (temp3->item);                   //j = the 2 node back item
                   break;
               }
               i2++;

           }
           //printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;



       }
       removeNode(ll,ll->size-1);

   }        //end for

   //printf("no of times sum == C is %d\n",n);


}

//sum check 7
//gives result like 1 1 2 2 3 for 9 which is shit
//going back to part 6 to redo
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2, *temp3;


   for(i=0;i<=C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, ll->size, (i+1));
       temp1 = ll->head;
       i2 = i;
       //printf("i is %d\n",i);
       j2 =i2;
       while(i2 != C)
       {

            i2 = j2;
           //printf("j2 is %d\n",j2);

           if(i2 == C)
           {
               break;
           }

           while(ll->sum<C)
           {

               if(((i2+1) == C) && (i != C))        //for the multiple 6
               {

                   break;
               }

                if((i2+1)!= C/2)
                {
                    insertNode(ll, ll->size, (i2+1));
                }

               //printf("i2 is %d\n",i2);

               if(ll->sum == C)
               {
                   temp3 = findNode(*ll,ll->size-2);
                   j2 = (temp3->item);                   //j = the 2 node back item
                   break;
               }
               i2++;

           }
           //printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;



       }
       removeNode(ll,ll->size-1);

   }        //end for

   //printf("no of times sum == C is %d\n",n);


}


//sum check for loop redundant
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2, *temp3;


   for(i=1;i<=C;i++)    //creating LL of 1 to 6
   {
       insertNode(ll, ll->size, i);
       temp1 = ll->head;
       i2 = i+1;
       //i2 is 2

       printf("i2 is %d\n",i2);
       j2 = i2;
       while(i2 <= C)
       {

            i2 = j2;
           //printf("j2 is %d\n",j2);

           if(i2 == C)
           {
               break;
           }

           while(ll->sum<C)
           {
               insertNode(ll, ll->size, (i2));      //inserts 2 in
               //printf("j2 is %d\n",j2);

               if(ll->sum == C)
               {
                   temp3 = findNode(*ll,ll->size-2);
                   j2 = temp3->item;                   //j = the 2 node back item
                   break;
               }
               i2++;

           }
           //printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;



       }    //endwhile
       /*
       if(i2 == C)
       {
           printf(" %d ",ll->head->item);
       }*/
       removeNode(ll,ll->size-1);


   }        //end for

   //printf("no of times sum == C is %d\n",n);


}

void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2, *temp3;


   for(i=0;i<C;i++)    //creating LL of 1 to 6
   {
       insertNode(ll, ll->size, (i+1));
       temp1 = ll->head;
       i2 = i+1;
       //i2 is no longer an index, but a number to insert
       
       printf("i2 is %d\n",i2);
       j2 = i2;
       while(i2 <= C)
       {

            i2 = j2;
           //printf("j2 is %d\n",j2);

           if(i2 == C)
           {
               break;
           }

           while(ll->sum<C)
           {



               insertNode(ll, ll->size, (i2+1));
               //printf("j2 is %d\n",j2);

               if(ll->sum == C)
               {
                   temp3 = findNode(*ll,ll->size-2);
                   j2 = temp3->item;                   //j = the 2 node back item
                   break;
               }
               i2++;

           }
           //printf("sum is %d\n", ll->sum);

            temp2 = temp1;
            //printf("A\n");
            if(ll->sum == C)
            {
                n++;
                //printf("B\n");
                for(j=0;j<ll->size;j++)    //from 1 to 6
                {

                    //printf("C\n");
                    printf(" %d ",temp2->item);
                    temp2 = temp2->next;

                }
                printf("\n");

            }



           //back track 2 slots
           removeNode(ll,ll->size-1);
           removeNode(ll,ll->size-1);

           j2++;



       }    //endwhile
       /*
       if(i2 == C)
       {
           printf(" %d ",ll->head->item);
       }*/
       removeNode(ll,ll->size-1);


   }        //end for

   //printf("no of times sum == C is %d\n",n);


}


//FINALLY SOLVED SUM CHECK SAMPLE TEST CASE PASSED
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2;

   ListNode *temp1, *temp2, *temp3;

    i=1;
   insertNode(ll, ll->size, i);
   temp1 = ll->head;
   i2 = i+1;
   //i2 is 2

   //printf("i2 is %d\n",i2);
   j2 = i2;
   while(i2 <= C)
   {

        i2 = j2;
       //printf("j2 is %d\n",j2);

       if(i2 == C)
       {
           break;
       }

       while(ll->sum<C)
       {
           insertNode(ll, ll->size, (i2));      //inserts 2 in
           //printf("j2 is %d\n",j2);

           if(ll->sum == C)
           {
               temp3 = findNode(*ll,ll->size-2);
               j2 = temp3->item;                   //j = the 2 node back item
               break;
           }
           i2++;

       }
       //printf("sum is %d\n", ll->sum);

        temp2 = temp1;
        //printf("A\n");
        if(ll->sum == C)
        {
            n++;
            //printf("B\n");
            for(j=0;j<ll->size;j++)    //from 1 to 6
            {

                //printf("C\n");
                printf(" %d ",temp2->item);
                temp2 = temp2->next;

            }
            printf("\n");

        }



       //back track 2 slots
       removeNode(ll,ll->size-1);
       removeNode(ll,ll->size-1);

       j2++;



   }    //endwhile
    printf(" %d", C);

}




//Adding shit to array list
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   int i, i2, j;

   ArrayNode *temp1, *pre;

   ListNode *temp2;

   for(i=0;i<C;i++)    //creating LL of 1 t 6
   {
       insertNode(ll, i, (i+1));
   }


   temp2 = ll->head;
   al->size = 1;
   al->head = (ArrayNode*) malloc(sizeof(ArrayNode));
   temp1 = al->head;

   temp1->sizeArray = ll->size;
   //printf("size2 is %d\n ",temp1->sizeArray);

   for(j=0; j<ll->size;j++)
   {
       temp1->itemArray[j] = temp2->item;
       temp2 = temp2->next;
   }


}




//merger part 1
//removeNode error
void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
   //1,2,3 =6, can backtrack to 1 instead of 2 as the 2 branch everything probably would not worked
   int i, i2,n =0,j,j2, j3;

   int v;

   ListNode *temp1, *temp2, *temp3, *temp4;

   ArrayNode *ArTemp1;

    i=1;
   insertNode(ll, ll->size, i);
   temp1 = ll->head;
   i2 = i+1;
   //i2 is 2

   //printf("i2 is %d\n",i2);
   j2 = i2;

   al->size = 1;
   al->head = (ArrayNode*) malloc(sizeof(ArrayNode));
   ArTemp1 = al->head;


   while(i2 <= C)
   {

        i2 = j2;
       //printf("j2 is %d\n",j2);

       if(i2 == C)
       {
           break;
       }

       while(ll->sum<C)
       {
           insertNode(ll, ll->size, (i2));      //inserts 2 in
           //printf("j2 is %d\n",j2);

           if(ll->sum == C)
           {
               temp3 = findNode(*ll,ll->size-2);
               j2 = temp3->item;                   //j = the 2 node back item
               break;
           }
           i2++;

       }
       //printf("sum is %d\n", ll->sum);

        temp2 = temp1;
        //printf("A\n");
        if(ll->sum == C)
        {
            n++;
            printf("temp 2 item is %d\n",temp2->item);

            ArTemp1->sizeArray = ll->size;
            printf("B\n");
            for(j3=0; j3<ll->size;j3++)
            {
                 v = temp2->item;
                 ArTemp1->itemArray[j3] = v;
                 printf(" %d ",v);
                 temp2 = temp2->next;
            }
            printf("C\n");

        }


        printf("item is %d\n",ll->head->item);
       //back track 2 slots
       temp4 = findNode(*ll,ll->size-1);
       printf("item is %d\n",temp4->item);
       printf("size2 is %d\n",ll->size);
       removeNode(ll,2);
        printf("F\n");
       j2++;

        ArTemp1->next = (ArrayNode*) malloc(sizeof(ArrayNode));

        ArTemp1 = ArTemp1->next;

   }    //endwhile
    al->size = n;
    printf(" %d", C);

}