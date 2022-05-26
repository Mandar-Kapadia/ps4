/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Mandar Kapadia


Hours to complete assignment: 3 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

In this assignment I created a CircularBuffer API that is a circualar arrray
That will create a array of a size and will only add if space. I have 6 functions
a function that will tell the size, a function that adds, a function that returns and delete first item,
a function to return first item, a funtions that tell if empty and a function that tells if full.




/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I used an array structures to make my buffer. My array structure is a circualar 
array structure with a couple functions to make it easy.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
I implemented 6 diffrent functions. I have the isEmpty which is a function that
will see if size == 0(size holds how many sizes there are) and will return true or false.Next is isFull which will compare if size greater then
or equal to length(holds the length of tyhe array). we then have size which returns the amount of elemets in the size.
Enqueue is a function that will add if not full and it will add to the back by doing (back+1) % length. We next 
will dequeue which will check is the array is empty if not then it will return the elemet subtract a size and if there is one elemet is resets the array.
Next we have peek which is an array which simply returns the top if the array is not empty.
 




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed every part becuase I tested it in boost and it worked with no flaws and I 
also ran some of my own tests.




/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

My CircularBuffer implementation pass all the unit tests and it does so because 
I tested each function. For the constructed I tested 0 and a negitive value to check 
if it would check if it would throw an error if an incorrect input came and it does.
I also check if is full and empty works if there is nothing in the array if there is something.
Next I check peek and dequeue which I tested by trying to return a empty array, and a error with something in it and it threw an error in the empty
and return correct elemet. In dequeue I also test if the elemets were erased which it was. Next I checked
Enqueue which was done by adding elemets and when elemets where full if it added and when added did they add the right number.



/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/

 In my performance for time I think I have very instant for dequeue and peek it is 0(1) becuase 
 you have a front element. For Enqueue I think its close to 0(1) because you need to do small math which is (back+1)% length
 which will give you the correct place to enter and will enter. I think the size,isFull, and isEmpty are all o(1) becuas they are 
 they are eith a bool statment or a returning a function. For space I think its close to o(n) becuase I am only storying
 the amount of element as needed which 2 more variables.




/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
    I kinda got help from dr.daly for tell me to use a circualar array.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
