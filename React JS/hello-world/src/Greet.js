import React from "react";

function SayHey(){
  const sayHi = () => {
    console.log("Hey there");
  };

  return (
    <div>
      <h4>This the app component</h4>
      <button onClick={sayHi}>Hello Malick!!!</button>
    </div>
    );
};
export default SayHey;
