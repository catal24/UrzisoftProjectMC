#ifndef MATRIX_CLIENT_H
#define MATRIX_CLIENT_H

#include <vector>
#include <string>
#include <asio.hpp>

class MatrixClient {
public:
    MatrixClient(const std::string& serverAddress, const std::string& port);

    // Connect to the server and receive the matrix
    std::vector<std::vector<int>> receiveMatrix();

    // Print the received matrix
    void printMatrix(const std::vector<std::vector<int>>& matrix) const;

private:
    std::string serverAddress_;
    std::string port_;
    asio::io_context ioContext_;
    asio::ip::tcp::socket socket_;

    void connectToServer();
    std::string receiveData();
    std::vector<std::vector<int>> deserializeMatrix(const std::string& data) const;
};

#endif // MATRIX_CLIENT_H
