program part1
  integer :: n, a, b
  integer, dimension(12) :: bits
  character(len = 12) :: s
  
  n = 0
  do i = 1, 12
     bits(i) = 0
  end do
  do
     read (5, 12, end=20) s
12   format(a12)
     n = n+1
     do i = 1, 12
        if (s(i:i) == '1') then
           bits(i) = bits(i) + 1
        end if
     end do
  end do
20 a = 0
  b = 0
  do i = 1, 12
     a = a * 2
     b = b * 2
     if (bits(i) > n/2) then
        a = a + 1
     else
        b = b + 1
     end if
  end do
  write(*, '(I0)') a * b
end program part1
