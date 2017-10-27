%Rules
  %Check if element is Head or in Tail.
  is_member(X, [X|_]).
  is_member(X, [_|T]) :- is_member(X, T).

  %First Element:
  is_first_element(X, [X|_]).

  %Last Element:
  is_last_element(X,[X]).
  is_last_element(X,[_|T]) :- is_last_element(X,T).

  %Two Adjacent Elements
  is_two_adjacent(X, Y, [X,Y|_]).
  is_two_adjacent(X, Y, [_|T]) :- is_two_adjacent(X, Y, T).

  %Three Adjacent Elements
  is_three_adjacent(X, Y, Z, [X,Y,Z|_]).
  is_three_adjacent(X, Y, Z, [_|T]) :- is_three_adjacent(X, Y, Z, T).

  %Append List1 to List2 creating List3
  append_list([], L2, L2).
  append_list([X|T1], L2, [X|T3]):- append_list(T1,L2,T3).

  %Delete element from list
  delete_element(X, [X|T], T).
  delete_element(X, [H|T], [H|T1]) :- delete_element(X, T, T1).

  %Append Element
  append_element(L, [], [L]).
  append_element(E, [X|T1], [X|T3]) :- append_list(T1,[E],T3).

  %Insert Element in a list
  insert_element(X, L, XL) :- delete_element(X, XL, L).

  %Compute the length of the list
  list_length([], 0).
  list_length([_|T], N) :- list_length(T, N1), N is 1 + N1.

  %Reverse order of a list
  accRev([H|T],A,R):-  accRev(T,[H|A],R).
  accRev([],A,A).
  reverse_list(L,R):-  accRev(L,[],R).

  %Check whether a list is a palindrome
  is_palindrome(L) :- reverse_list(L,R), L == R.

  %Displays the list
  display([]).
  display([H|T]) :- write(H), write(,), tab(1), display(T).
