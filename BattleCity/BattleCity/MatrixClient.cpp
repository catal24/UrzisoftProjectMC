#include "MatrixClient.h"
#include <iostream>
#include <sstream>

using asio::ip::tcp;

// Constructor
MatrixClient::MatrixClient(const std::string& serverAddress, const std::string& port)
    : serverAddress_(serverAddress), port_(port), ioContext_(), socket_(ioContext_) {}

// Connect to the server
void MatrixClient::connectToServer() {
    tcp::resolver resolver(ioContext_);
    auto endpoints = resolver.resolve(serverAddress_, port_);
    asio::connect(socket_, endpoints);
}

// Receive serialized data
std::string MatrixClient::receiveData() {
    std::vector<char> buffer(1024);
    size_t length = socket_.read_some(asio::buffer(buffer));
    return std::string(buffer.begin(), buffer.begin() + length);
}

// Deserialize the received data into a matrix
std::vector<std::vector<int>> MatrixClient::deserializeMatrix(const std::string& data) const {
    std::istringstream iss(data);
    size_t rows, cols;
    iss >> rows >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            iss >> matrix[i][j];
        }
    }
    return matrix;
}

// Receive a matrix from the server
std::vector<std::vector<int>> MatrixClient::receiveMatrix() {
    connectToServer();
    std::string serializedData = receiveData();
    return deserializeMatrix(serializedData);
}

// Print the matrix
void MatrixClient::printMatrix(const std::vector<std::vector<int>>& matrix) const {
    std::cout << "Received matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}
