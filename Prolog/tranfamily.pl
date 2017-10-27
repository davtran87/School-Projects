






%Facts:

  m([david, tuan, viet, vu, anh, dung, huy, quocvinh, thinh, quan, chu, thien, ho, philip, ong]).
  f([ngocba, tien, vi, jennifer, hanh, thi, sung, dong, loc, chi, mo,
     quynh, huong, minh, van, sylvi, sophie, amy, thin, ba]).
  family([ anh, ngocba, [david, tuan, viet, vu, tien, vi, jennifer] ]).
  family([ dung, mo, [huy, quocvinh, dong, sung, chi, loc] ]).
  family([ thinh, hanh, [quan, quynh] ]).
  family([ chu, thi, [minh, huong] ]).
  family([ thien, van, [ho, sylvi, sophie] ]).
  family([ anh, thin, [amy, philip] ]).
  family([ ong, ba, [ngocba, dung, hanh, thi, van] ]).
  family([ onglon, balon, [ong] ]).
  family([ baclon, noilon, [ba] ]).

%Rules:

  %Gender:
  male(X) :- m(List), member(X, List).
  female(X) :- f(List), member(X, List).

  %Parents:
  father(X,Y) :- family([X, _, List]), member(Y, List).
  mother(X,Y) :- family([_, X, List]), member(Y, List).
  parent(X,Y) :- father(X,Y); mother(X,Y).

  %Siblings2:with 2 same parents
  siblings2(X,Y) :- parent(P1, X), parent(P1, Y), parent(P2, X),
                    parent(P2, Y), P1 \= P2, X \= Y.
  brother2(X,Y) :- siblings2(X,Y), male(X).
  sister2(X,Y) :- siblings2(X,Y), female(X).

  %Siblings1:with 1 same parent aka half siblings
  siblings1(X,Y) :- parent(P, X), parent(P, Y), X \= Y, not(siblings2(X,Y)).
  brother1(X,Y) :- siblings1(X,Y), male(X).
  sister1(X,Y) :- siblings1(X,Y), female(X).

  %Cousins:
  cousins(X,Y) :- parent(P1,X), parent(P2,Y), siblings2(P1,P2).

  %Uncle:
  uncle(X,Y) :- cousins(C,Y), parent(X,C), male(X).

  %Aunt:
  aunt(X,Y) :- cousins(C,Y), parent(X,C), female(X).

  %Grandparents:
  grandparent(X,Y) :- parent(X,P), parent(P,Y).

  %Great Grandparent:
  greatgrandparent(X,Y) :- parent(X,GP), grandparent(GP,Y).

  %Grandchild:
  grandchild(X,Y) :- parent(P,X), parent(Y,P).
  grandson(X,Y) :- grandchild(X,Y), male(X).
  granddaughter(X,Y) :- grandchild(X,Y), female(X).

  %Ancestor:
  ancestor(X,Y) :- parent(X,Y); grandparent(X,Y); greatgrandparent(X,Y).
