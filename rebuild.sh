#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=== Building WeeHub ===${NC}"

# Navigate to build directory
cd build || exit 1

# Build the project
if cmake --build .; then
    echo -e "${GREEN}✓ Build successful!${NC}"
    echo -e "${YELLOW}=== Running WeeHub ===${NC}"
    echo ""
    ./src/Weehub
    EXIT_CODE=$?
    echo ""
    if [ $EXIT_CODE -eq 0 ]; then
        echo -e "${GREEN}✓ Program exited successfully${NC}"
    else
        echo -e "${RED}✗ Program exited with code $EXIT_CODE${NC}"
    fi
else
    echo -e "${RED}✗ Build failed!${NC}"
    exit 1
fi