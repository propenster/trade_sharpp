# trade_sharpp - A complete suite of High-Frequency Trading setup with C++ backend, C# .NET 8 Frontend (ClientApp), RPC for Order Entry and MarketData FixEngine

## A complete suite of High-Frequency Trading setup with C++ backend, C# .NET 8 Frontend (ClientApp), RPC for Order Entry and MarketData FixEngine


### How it works...


- the Client App written in either C#/.NET 8 or Typescript (as in React) either exposes APIs that users submit trade orders through...

- It passes the trade order to the highly-optimized C++ backend via RPC using Protobuf...

- C++ backend submits order requests to QUICKFix Exchange Simulator through the QuickFix TradeClient...

- Protobuf backend -> QuickFix TradeClient -> Executor ->
- ->back to QuickFix TradeClient -> back to Protobuf Backend -> then to CLIENT App (C# .NET Core)