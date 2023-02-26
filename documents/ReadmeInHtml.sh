pandoc -f markdown -t html5 -o Documentation.html ../README.md --css=ReadmeInHtmlStyle.css --self-contained
firefox Readme.html