// #pointers--> not just stores address also tells ki who owns the memoey and who can delete it 
/*
┌──────────────┐
│   Stack      │  ← local variables
├──────────────┤
│   Heap       │  ← new / make_unique / make_shared
├──────────────┤
│   Global     │  ← global/static vars
├──────────────┤
│   Code/Text  │
└──────────────┘
*/
/*
Raw Pointers:-
OrderBook* p;---> fast but unsafe no ownership  
IOrderBook* book=new IOrderBook();
Stack:
book ───────► Heap: OrderBook 
deletion problem if forget then memory leak
*/
/*
Stack Objects:-
OrderBook book;
Stack:
book (OrderBook object)
problems:-
interface nahi 
Stack object = tight coupling
*/
/*
UNIQUE_PTR:-
single owner and safe 
unique_ptr<IOrderBook>book=make_unique<OrderBook>();
Stack:
book (unique_ptr)
 └── owns ──► Heap: OrderBook
 ONLY book owns OrderBook not copy just move
 auto b2 = book;        //wrong 
auto b2 = move(book); // right 
*/
//Stack cleanup → Heap cleanup → ZERO LEAK
//Isko bolte hain RAII

/*
shared pointer :- multiple owners and slow 
shared_ptr<IOrderBook> book = make_shared<OrderBook>();

*/
/*
weak pointer
weak_ptr<OrderBook> wp;
breaks cycles, obersever cannot own
used with shared pointer

*/
/*
References
OrderBook& ref
not null, no ownership, safe
*/
/*
why WHY make_unique NOT new
auto p=make_unique<OrderBook>();
why?
single allocation, execution safe
avoid tio do :-unique_ptr<OrderBook> p(new OrderBook());
*/
// why i see unique pointer i must immediately know 
// single owner, heap allocation, polymerphic, lifetime scoped not shared
