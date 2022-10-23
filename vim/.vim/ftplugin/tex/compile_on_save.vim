autocmd BufWritePost * cd %:p:h | silent! execute("!pdflatex %") | redraw!
