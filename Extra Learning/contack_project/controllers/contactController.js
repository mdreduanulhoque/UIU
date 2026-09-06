const { request } = require("express");
const asyncHandler = require("express-async-handler")

// @dec Get all contacts
// @route GET /api/contacts
// @access public
const getContacts = asyncHandler( async (req,res)=>{
    res.json({ message: "Get all contacts"});
});

// @dec Create new contacts
// @route POST /api/contacts
// @access public
const createContact = asyncHandler( async (req,res)=>{
    console.log(req.body);

    const {name, email, phone} = req.body;
    if(!name || !email || !phone){
        res.status(400);
        throw new Error("All fields are mandatory");
    }

    res.json({ message: "Create contacts"});
});

// @dec Get contact by ID
// @route GET /api/contacts/:id
// @access public
const getContact = asyncHandler( async (req,res)=>{
    res.json({ message: `Get the contact for ${req.params.id}`});
});

// @dec Update contact by ID
// @route PUT /api/contacts/:id
// @access public
const updateCotact = asyncHandler( async (req,res)=>{
    res.json({ message: `Update the contact for ${req.params.id}`});
});

// @dec Delete contact by ID
// @route DELETE /api/contacts/:id
// @access public
const deleteCotact = asyncHandler( async (req,res)=>{
    res.json({ message: `Delete the contact for ${req.params.id}`});
});


module.exports = {getContacts, createContact, getContact, updateCotact, deleteCotact};