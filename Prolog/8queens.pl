queens([]).
queens([X/Y|Rest]) :- queens(Rest), member(Y,[1,2,3,4,5,6,7,8]),
                      goodposition(X/Y,Rest).

goodposition(_,[]).
goodposition(X/Y,[X1/Y1|Rest]) :- Y =\= Y1, abs(Y1-Y) =\= abs(X1-X),
                                  goodposition(X/Y,Rest).

qpositions([1/Y1,2/Y2,3/Y3,4/Y4,5/Y5,6/Y6,7/Y7,8/Y8]).
main(Solution) :- qpositions(Solution), queens(Solution).
