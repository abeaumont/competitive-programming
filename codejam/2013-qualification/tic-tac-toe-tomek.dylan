module: tic-tac-toe-tomek
url: https://code.google.com/codejam/contest/2270488/dashboard#s=p0

define library tic-tac-toe-tomek
  use common-dylan;
  use io;
end library tic-tac-toe-tomek;

define module tic-tac-toe-tomek
  use common-dylan, exclude: { format-to-string };
  use format-out;
  use streams;
  use standard-io;
end module tic-tac-toe-tomek;

define function read-board() => (board :: <string>)
  join(range(to: 4), "", key: method (i) read-line(*standard-input*) end);
end function read-board;

define function check (board :: <string>)
  local method element? (n, ch)
          member?(board[n], list(ch, 'T'))
        end method element?;
  local method rows? (ch)
          any?(method(i)
                   every?(rcurry(element?, ch), range(from: i, to: i + 3))
               end, range(to: 15, by: 4));
        end method rows?;
  local method columns? (ch)
          any?(method(i)
                   every?(rcurry(element?, ch), range(from: i, to: 15, by: 4))
               end, range(to: 3));
        end method columns?;
  local method diagonals? (ch)
          any?(curry(every?, rcurry(element?, ch)),
               list(range(to: 15, by: 5), range(from: 3, to: 12, by: 3)));
        end method diagonals?;
  local method full? ()
          ~any?(curry(\==, '.'),  board);
        end method full?;
  case
    rows?('X') | columns?('X') | diagonals?('X') => #"x";
    rows?('O') | columns?('O') | diagonals?('O') => #"o";
    full?() => #"draw";
    otherwise => #"incomplete";
  end case;
end function check;

define function print (i, status)
  format-out("Case #%d: %s\n", i,
             select (status)
               #"draw" => "Draw";
               #"incomplete" => "Game has not completed";
               #"x" => "X won";
               #"o" => "O won";
             end);
end function print;

define function main (name :: <string>, arguments :: <vector>)
  for (i from 1 to string-to-integer(read-line(*standard-input*)))
    print(i, check(read-board()));
  end for;
  exit-application(0);
end function main;

main(application-name(), application-arguments());
