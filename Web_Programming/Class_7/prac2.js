document.getElementById("submit-button").addEventListener("click", function () {
  let weight = document.getElementById("weight-input").value;

  let height = document.getElementById("height-input").value;

  let bmi = weight / Math.pow(height, 2);

  console.log(bmi);

  document.getElementById("show-output").innerHTML = `<b>Your BMI is ${bmi}</b>`
});
