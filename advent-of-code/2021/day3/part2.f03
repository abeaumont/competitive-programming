program part2
  integer :: n, n2, a, b, bit
  character(len = 12), dimension(1000) :: s, t

  n = 1000
  bit = 0
  do i = 1, n
     read (5, 9, end=12) s(i)
9    format(a12)
     t(i) = s(i)
  end do
12 do i = 1, 12
     bit = 0
     do j = 1, n
        if (s(j)(i:i) == '1') then
           bit = bit + 1
        end if
     end do
     n2 = n
     j = 1
     do while (j <= n2)
        if ((bit*2 >= n .and. s(j)(i:i) == '0') .or. (bit*2 < n .and. s(j)(i:i) == '1')) then
           s(j) = s(n2)
           n2 = n2 - 1
        else
           j = j + 1
        end if
     end do
     n = n2
  end do
  n = 1000
  do i = 1, 12
     bit = 0
     do j = 1, n
        if (t(j)(i:i) == '1') then
           bit = bit + 1
        end if
     end do
     n2 = n
     j = 1
     do while (j <= n2)
        if ((bit*2 >= n .and. t(j)(i:i) == '1') .or. (bit*2 < n .and. t(j)(i:i) == '0')) then
           t(j) = t(n2)
           n2 = n2 - 1
        else
           j = j + 1
        end if
     end do
     n = n2
  end do
  a = 0
  b = 0
  k = 1
  do i = 12, 1, -1
     if (s(1)(i:i) == '1') then
        a = a + k
     end if
     if (t(1)(i:i) == '1') then
        b = b + k
     end if
     k = k * 2
  end do
  write(*, '(I0)') a * b
end program part2
