let calory = 0.0;
let goal = 2000;
let total_calory = 0.0;
let meal_count = 0;
let lst = "";

document.getElementById("add-calory").addEventListener("click", function () {
    calory = Number(document.getElementById("calory-input").value);
    total_calory += calory;
    meal_count++;
    lst += `   ${calory}   `;

    document.getElementById("consumed-list").innerHTML = `Consumed Calories: ${lst}`;

    if(total_calory <= 800){
        document.getElementById("feedback").innerHTML = `You are off to a healthy start!`;
    }else if(total_calory >= 801 && total_calory <= 1600){
        document.getElementById("feedback").innerHTML = `Good progress, keep it balanced!`;
    }else if(total_calory >= 1601 && total_calory <= 1999){
        document.getElementById("feedback").innerHTML = `Almost at your limit!`;
    }else{
        document.getElementById("feedback").innerHTML = `Goal reached! Stay mindful!`;
    }

    if(meal_count > 10 && total_calory < goal){
        document.getElementById("extra-feedback").innerHTML = `Be cautious of frequent snacking!`;
    }

    document.getElementById("calory-input").value = "";
    
});