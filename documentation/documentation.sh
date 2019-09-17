pandoc -f markdown -t html5 -o documentation.html ../README.md -c style.css
firefox documentation.html