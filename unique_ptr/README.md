# std::unique_ptr Practice

## Compile

```bash
g++ -g -o a Image.cpp ImageManager.cpp main.cpp
```

## Check Memory Leak

```bash
valgrind -s --leak-check=full --track-origins=yes ./a
```
