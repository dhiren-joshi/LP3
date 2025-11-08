// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.19;

contract BankAccount {
    mapping(address => uint256) private balances;
    mapping(address => bool) private isUser;

    event AccountCreated(address indexed user, uint256 amount, string message);
    event Deposit(address indexed user, uint256 amount, string message);
    event Withdraw(address indexed user, uint256 amount, string message);

    // Create a new bank account
    function createAccount() public payable returns (string memory) {
        require(!isUser[msg.sender], "Account already exists!");
        isUser[msg.sender] = true;
        balances[msg.sender] = msg.value;
        emit AccountCreated(msg.sender, msg.value, "Account created successfully!");
        return "Account created successfully!";
    }

    // Deposit Ether to your account
    function deposit() public payable returns (string memory) {
        require(isUser[msg.sender], "You do not have an account!");
        require(msg.value > 0, "Deposit amount must be greater than 0!");
        balances[msg.sender] += msg.value;
        emit Deposit(msg.sender, msg.value, "Deposit successful!");
        return "Deposit successful!";
    }

    // Withdraw Ether from your account
    function withdraw(uint256 amount) public returns (string memory) {
        require(isUser[msg.sender], "You do not have an account!");
        require(amount > 0, "Withdrawal amount must be greater than 0!");
        require(balances[msg.sender] >= amount, "Insufficient balance!");
        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
        emit Withdraw(msg.sender, amount, "Withdrawal successful!");
        return "Withdrawal successful!";
    }

    // Show your account balance
    function showBalance() public view returns (uint256, string memory) {
        require(isUser[msg.sender], "You do not have an account!");
        return (balances[msg.sender], "Here is your current account balance.");
    }
}
