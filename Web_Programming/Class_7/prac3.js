document.getElementById("add-button").addEventListener("click", function () {
  let num_1 = Number(document.getElementById("first-input").value);

  let num_2 = Number(document.getElementById("second-input").value);

  let sum = num_1 + num_2;

  document.getElementById("show-output").innerHTML = `<b>Your Sum is ${sum}</b>`
});

document.getElementById("subtract-button").addEventListener("click", function () {
  let num_1 = Number(document.getElementById("first-input").value);

  let num_2 = Number(document.getElementById("second-input").value);

  let subtract = num_1 - num_2;

  document.getElementById("show-output").innerHTML = `<b>Your Subtraction is ${subtract}</b>`
});


document.getElementById("multiply-button").addEventListener("click", function () {
  let num_1 = Number(document.getElementById("first-input").value);

  let num_2 = Number(document.getElementById("second-input").value);

  let multiply = num_1 * num_2;

  document.getElementById("show-output").innerHTML = `<b>Your Multiplication is ${multiply}</b>`
});

document.getElementById("divide-button").addEventListener("click", function () {
  let num_1 = Number(document.getElementById("first-input").value);

  let num_2 = Number(document.getElementById("second-input").value);

  let division = num_1 / num_2;

  document.getElementById("show-output").innerHTML = `<b>Your Division is ${division}</b>`
});

