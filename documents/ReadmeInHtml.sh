pandoc -f markdown -t html5 -o Readme.html ../README.md --css=ReadmeInHtmlStyle.css --self-contained
firefox Readme.html