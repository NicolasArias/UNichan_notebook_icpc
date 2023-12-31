syntax on

set number
set noerrorbells
set tabstop=2 softtabstop=2
se shiftwidth=2
set autoindent
set smartindent
set nowrap

nnoremap<F1> :!./%:r.out < in1 <CR>
nnoremap<F2> :!./%:r.out < in2 <CR>
nnoremap<F3> :!./%:r.out < in3 <CR>
nnoremap<F4> :!./%:r.out < in4 <CR>
nnoremap<F5> :w <bar> !g++ -Wextra -Wall -Wno-sign-conversion -fmax-errors=3 -DLOCAL -o %:r.out % -std=c++17<Enter>
nnoremap<F6> :%y+<CR>
nnoremap<F9> :!./%:r.out<Enter>
