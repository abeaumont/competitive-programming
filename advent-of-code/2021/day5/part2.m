#!/bin/octave -qf
coords = [];
while (true)
  try
    line = input('', 's');
  catch
    break
  end_try_catch
  [_, _, _, _, t, _] = regexp(line, '(\d+),(\d+) -> (\d+),(\d+)');
  x = cell2mat(t);
  coords = [coords, [str2num(x{1,1})+1; str2num(x{1,2})+1; str2num(x{1,3})+1; str2num(x{1,4})+1]];
endwhile
n = max(max(coords));
m = zeros(n:n);
for c = coords
  if c(1) == c(3)
    for i = min(c(2), c(4)) : max(c(2), (c(4)))
      m(i, c(1)) += 1;
    endfor
  elseif c(2) == c(4)
    for i = min(c(1), c(3)) : max(c(1), (c(3)))
      m(c(2), i) += 1;
    endfor
  elseif c(2) - c(1) == c(4) - c(3)
    for i = min(c(1), c(3)) : max(c(1), (c(3)))
      m(c(2) - c(1) + i, i) += 1;
    endfor
  elseif c(1) < c(3)
    for i = 0 : c(3) - c(1)
      m(c(2) - i, c(1) + i) += 1;
    endfor
  else      
    for i = 0 : c(1) - c(3)
      m(c(2) + i, c(1) - i) += 1;
    endfor
  endif
endfor
disp(sum(sum(m > 1)))
