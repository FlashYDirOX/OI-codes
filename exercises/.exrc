if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <silent> <Plug>StopMarkdownPreview :if exists(':MarkdownPreviewStop') | exec 'MarkdownPreviewStop ' | endifa
nmap \p :cpre 
nmap \n :cnext 
nmap \l :Goyo
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
noremap <silent> <Plug>AirlineSelectNextTab :exe repeat(':tabn|', v:count1)
noremap <silent> <Plug>AirlineSelectPrevTab gT
noremap <silent> <Plug>AirlineSelectTab9 :9tabn
noremap <silent> <Plug>AirlineSelectTab8 :8tabn
noremap <silent> <Plug>AirlineSelectTab7 :7tabn
noremap <silent> <Plug>AirlineSelectTab6 :6tabn
noremap <silent> <Plug>AirlineSelectTab5 :5tabn
noremap <silent> <Plug>AirlineSelectTab4 :4tabn
noremap <silent> <Plug>AirlineSelectTab3 :3tabn
noremap <silent> <Plug>AirlineSelectTab2 :2tabn
noremap <silent> <Plug>AirlineSelectTab1 :1tabn
nmap <F2> :call Run() 
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
map <silent> <Plug>StopMarkdownPreview :if exists(':MarkdownPreviewStop') | exec 'MarkdownPreviewStop ' | endif
xnoremap <silent> <Plug>(Limelight) :Limelight
nnoremap <silent> <Plug>(Limelight) :set opfunc=limelight#operatorg@
nmap <F3> :NERDTreeToggle
nmap <F8> :TagbarToggle
nmap <F7> <Plug>MarkdownPreview
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set backupdir=~/.cache/vim/backup//
set cindent
set directory=~/.cache/vim/swap//
set fileencodings=ucs-bom,utf-8,default,latin1
set guifont=anonymous\ pro\ 13
set guioptions=
set helplang=en
set laststatus=2
set makeprg=g++\ %\ -o\ %<
set mouse=a
set ruler
set runtimepath=~/.vim,~/.vim/plugged/seoul256.vim/,~/.vim/plugged/gruvbox/,~/.vim/plugged/goyo.vim/,~/.vim/plugged/limelight.vim/,~/.vim/plugged/vim-markdown/,~/.vim/plugged/mathjax-support-for-mkdp/,~/.vim/plugged/markdown-preview.vim/,~/.vim/plugged/tagbar/,~/.vim/plugged/nerdtree/,~/.vim/plugged/vim-airline/,/usr/share/vim/vimfiles,/usr/share/vim/vim81,/usr/share/vim/vimfiles/after,~/.vim/after
set shiftwidth=4
set showtabline=2
set smartindent
set softtabstop=4
set suffixes=.bak,~,.o,.info,.swp,.aux,.bbl,.blg,.brf,.cb,.dvi,.idx,.ilg,.ind,.inx,.jpg,.log,.out,.png,.toc
set tabline=%!airline#extensions#tabline#get()
set tabstop=4
set ttimeoutlen=150
set undodir=~/.cache/vim/undo//
" vim: set ft=vim :
