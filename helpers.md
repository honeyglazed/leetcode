${toc}

# Helpers for C++

### Detecting diagonal and anti-diagonal cell

### std::string is just char****\* [] array
` char* c = &string[0]`

### Get all set bits
`
for (int i=0; i<=N; ++i) {
  if (bitset && (1 << i)) {
    cout << i;
  }
}
`
