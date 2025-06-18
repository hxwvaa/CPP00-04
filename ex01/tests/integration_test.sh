#!/bin/bash

echo "Running integration tests for PhoneBook..."

# Build the main program
cd ..
make clean
make

if [ $? -ne 0 ]; then
    echo "❌ Failed to build phonebook"
    exit 1
fi

echo "✓ PhoneBook built successfully"

# Test 1: Add contacts and search
echo "Testing ADD and SEARCH commands..."
echo -e "ADD\nJohn\nDoe\nJohnny\n123456789\nLoves cats\nADD\nJane\nSmith\nJay\n987654321\nHates dogs\nSEARCH\n0\nSEARCH\n1\nEXIT" | ./phonebook > test_output.tmp

if grep -q "Contact added successfully!" test_output.tmp && grep -q "First Name: John" test_output.tmp; then
    echo "✓ ADD and SEARCH test passed"
else
    echo "❌ ADD and SEARCH test failed"
    cat test_output.tmp
    exit 1
fi

# Test 2: Invalid index
echo "Testing invalid index..."
echo -e "ADD\nTest\nUser\nTU\n123\nSecret\nSEARCH\n99\nEXIT" | ./phonebook > test_output.tmp

if grep -q "Invalid index!" test_output.tmp; then
    echo "✓ Invalid index test passed"
else
    echo "❌ Invalid index test failed"
    exit 1
fi

# Test 3: Empty phonebook search
echo "Testing search on empty phonebook..."
echo -e "SEARCH\nEXIT" | ./phonebook > test_output.tmp

if grep -q "No contacts available!" test_output.tmp; then
    echo "✓ Empty phonebook search test passed"
else
    echo "❌ Empty phonebook search test failed"
    exit 1
fi

# Test 4: Invalid commands
echo "Testing invalid commands..."
echo -e "INVALID\nWRONG\nEXIT" | ./phonebook > test_output.tmp
    
if grep -q "Invalid command!" test_output.tmp; then
    echo "✓ Invalid command test passed"
else
    echo "❌ Invalid command test failed"
    exit 1
fi

# Clean up
rm -f test_output.tmp

echo "All integration tests passed! ✅"
