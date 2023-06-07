program matrix_multiplication
  implicit none

  ! Declare the size of the matrices
  integer, parameter :: n = 3
  
  ! Declare the matrices
  real :: A(n, n), B(n, n), C(n, n)
  
  ! Declare loop indices
  integer :: i, j, k
  
  ! Call subroutine to read matrices from file
  call read_matrices(A, B, n)
  
  ! Multiply matrices
  do i = 1, n
    do j = 1, n
      C(i,j) = 0.0
      do k = 1, n
        C(i,j) = C(i,j) + A(i,k) * B(k,j)
      end do
    end do
  end do
  
  ! Print result
  write(*,*) "Matrix C:"
  do i = 1, n
    write(*,'(3F10.2)') (C(i,j), j=1,n)
  end do

contains

  subroutine read_matrices(A, B, n)
    implicit none
    integer, intent(in) :: n
    real, intent(out) :: A(n,n), B(n,n)
    integer :: i, j
    
    ! Open the input file
    open(unit=10, file='matrices.txt', status='old')
    
    ! Read the first matrix
    do i = 1, n
      read(10,*) (A(i,j), j=1,n)
    end do
    
    ! Read the second matrix
    do i = 1, n
      read(10,*) (B(i,j), j=1,n)
    end do
    
    ! Close the input file
    close(unit=10)
    
  end subroutine read_matrices
  
end program matrix_multiplication
